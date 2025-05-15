#ifndef EDENCM_STATEMENTS_H
#define EDENCM_STATEMENTS_H

#include <string>
#include <vector>
#include <optional>
#include <variant>
#include <Vector3.h>

namespace eden_command {
	class CommandManager;

	using Argument = std::variant<std::string, int, float, bool, eden_utils::Vector3>;

	/// @brief Un statement es una sentencia o ejecucion de codigo. Esta puede ser de los tipos que hay abajo.
	struct EDENcm_Statement {
		virtual void execute(CommandManager& cm) = 0;
		virtual ~EDENcm_Statement() = default;
	};

	/// @brief Llamada a una funcion.
	struct EDENcm_FunctionCall : EDENcm_Statement {
		/// @brief Nombre de la funcion
		std::string name;

		/// @brief Argumentos de llamada a la funcion
		std::vector<Argument> args;

		/// @brief Linea en la que esta ejecutandose el comando.
		int line;

		/// @brief Columna en la que esta ejecutandose el comando.
		int column;

		void execute(CommandManager& cm) override;
	};

	/// @brief Bucle
	struct EDENcm_Loop : EDENcm_Statement {
		/// @brief Iteraciones del bucle
		int count;

		/// @brief Cuerpo del bucle (las funciones que hay dentro)
		std::vector<EDENcm_Statement*> body;

		void execute(CommandManager& cm) override;
	};

	/// @brief Salida debug
	struct EDENcm_DebugOutput : EDENcm_Statement {
		/// @brief Cuerpo de la salida debug (funciones que se van a sacar por debug)
		EDENcm_Statement* inner;

		void execute(CommandManager& cm) override;
	};

	/// @brief Deshabilitar el debug
	struct EDENcm_DisableDebug : EDENcm_Statement {
		/// @brief Cuerpo de la deshabilitacion (las funciones que van a estar deshabilitadas para salida debug)
		EDENcm_Statement* inner;

		/// @brief Opcional: rango de deshabilitacion
		std::optional<std::pair<int, int>> range;

		void execute(CommandManager& cm) override;
	};
}

#endif