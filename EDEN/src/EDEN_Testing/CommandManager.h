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

	class CommandManager : public Singleton<CommandManager> {
		/// @brief Para obtener la funcionalidad del patron Singleton
	public:
		friend Singleton<CommandManager>;

		EDEN_API static CommandManager* getInstance();

		EDEN_API inline void RegisterFunction(const std::string& functionName, std::function<void(std::vector<Argument>)> functionToRegister) {
			_currentFunctions[functionName] = functionToRegister;
		}

		template<typename... Ts>
		inline void ExecuteFunction(const std::string& functionName, Ts&&... args) {
			if (_currentFunctions.count(functionName)) {
				_currentFunctions[functionName](std::forward<Ts>(args)...);
			}
		}

		EDEN_API void ExecuteScripts();

		void setDebugLocation(int line, int column);

		void enableDebug();

		void disableDebug();

		void setDisableRange(int from, int to);

		void setCurrentStatementIndex(int index);

		EDEN_API void logDebugMessage(const std::string& message, bool isError = false);

	private:
		std::unordered_map<std::string, std::function<void(std::vector<Argument>)>> _currentFunctions;
		
		bool _debugEnabled = false;
		
		std::optional<std::pair<int, int>> _disabledRange;
		
		int _currentStatementIndex = 0;
		
		std::ofstream _debugFile;
		
		std::string _outputFilepath;
		
		int _debugLine = -1;
		
		int _debugColumn = -1;

		/// @brief Constructor por defecto
		EDEN_API CommandManager() = default;

		void openDebugFile(const std::string& scriptFilename);

		void closeDebugFile();
	};
}

#endif // !EDEN_COMMAND_MANAGER_H