#ifndef EDEN_COMMAND_MANAGER_H
#define EDEN_COMMAND_MANAGER_H

#include "Singleton.h"
#include <unordered_map>
#include <string>
#include <functional>
#include <any>
#include <type_traits>
#include <fstream>
#include <optional>
#include "EDENcm/EDENcmStatements.h"

namespace eden_command {

	struct ScriptExecutionContext {
		std::vector<EDENcm_Statement*> statements;
		size_t currentStatementIndex = 0;
		std::string debugName;
		bool finished = false;
	};

	class CommandManager : public Singleton<CommandManager> {
		/// @brief Para obtener la funcionalidad del patron Singleton
	public:
		friend Singleton<CommandManager>;

		EDEN_API ~CommandManager();

		EDEN_API static CommandManager* getInstance();

		EDEN_API inline void RegisterFunction(const std::string& functionName, std::function<void(std::vector<Argument>)> functionToRegister) {
			_currentFunctions[functionName] = functionToRegister;
		}

		template<typename... Ts>
		inline void ExecuteFunction(const std::string& functionName, Ts&&... args) {
			if (_currentFunctions.count(functionName)) {
				_currentFunctions[functionName](std::forward<Ts>(args)...);
			}
			else {
				stopCurrentScript();
			}
		}

		EDEN_API void ExecuteScripts();

		void stopCurrentScript();

		void setDebugLocation(int line, int column);

		void enableDebug();

		void disableDebug();

		void startWait(float seconds);

		void setDisableRange(int from, int to);

		bool isWaiting() const;

		EDEN_API void Update(float dT);

		void setCurrentStatementIndex(int index);

		EDEN_API void logDebugMessage(const std::string& message, bool isError = false);

	private:
		std::unordered_map<std::string, std::function<void(std::vector<Argument>)>> _currentFunctions;

		std::vector<ScriptExecutionContext> _activeScripts;
		
		bool _debugEnabled = false;
		
		std::optional<std::pair<int, int>> _disabledRange;
		
		int _currentStatementIndex = 0;
		
		std::ofstream _debugFile;
		
		std::string _outputFilepath;
		
		int _currentScripts = 0;

		int _debugLine = -1;
		
		int _debugColumn = -1;

		float _time = 0.0f;

		float _waitTime = 0.0f;

		/// @brief Constructor por defecto
		EDEN_API CommandManager() = default;

		void openDebugFile(const std::string& scriptFilename);

		void closeDebugFile();
	};
}

#endif // !EDEN_COMMAND_MANAGER_H