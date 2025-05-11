#ifndef EDEN_COMMAND_MANAGER_H
#define EDEN_COMMAND_MANAGER_H

#include "Singleton.h"
#include <unordered_map>
#include <string>
#include <functional>
#include <any>
#include <type_traits>

namespace eden_command {

	class CommandManager : public Singleton<CommandManager>
	{
		/// @brief Para obtener la funcionalidad del patron Singleton
	private:
		std::unordered_map<std::string, std::function<void(std::vector<std::any>)>> _currentFunctions;

		/// @brief Constructor por defecto
		EDEN_API CommandManager() = default;
	public:
		friend Singleton<CommandManager>;
		EDEN_API static CommandManager* getInstance();

		EDEN_API inline void RegisterFunction(const std::string& functionName, std::function<void(std::vector<std::any>)> functionToRegister) {
			_currentFunctions[functionName] = functionToRegister;
		}

		template<typename... Ts>
		EDEN_API inline void ExecuteFunction(const std::string& functionName, Ts&&... args) {
			if (_currentFunctions.count(functionName)){
				std::vector<std::any> vecArgs{ std::forward<Ts>(args)... };
				_currentFunctions[functionName](vecArgs);
			}
		}
	};
}
#include <iostream>


#endif // !EDEN_COMMAND_MANAGER_H