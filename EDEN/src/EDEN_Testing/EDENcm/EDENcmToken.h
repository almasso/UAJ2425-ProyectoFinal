#ifndef EDENCM_TOKEN_H
#define EDENCM_TOKEN_H

#include <string>

namespace eden_command {
	/// @brief Definimos todos los tipos de token (simbolos permitidos) de nuestro lenguaje
	enum class EDENcm_TokenType {
		Identifier, // Identificadores
		Number, // Numeros.
		String, // Cadenas de texto,
		KeywordLoop, // Palabra reservada "loop" para bucles.
		KeywordDebug, // Palabra reservada "debug" para salida debug.
		KeywordDisable, // Palabra reservada "disable" para desactivar salida debug.
		KeywordWait, // Palabra reservada "wait" para esperar entre instruccion e instruccion.
		SymbolLeftShift, // Simbolo <<
		SymbolRightShift, // Simbolo >>
		Comma, // Coma (simbolo ,)
		Semicolon, // Punto y coma (simbolo ;)
		Colon, // Dos puntos (simbolo :)
		ParenOpen, // Simbolo (
		ParenClose, // Simbolo )
		BraceOpen, // Simbolo {
		BraceClose, // Simbolo }
		BracketOpen, // Simbolo [
		BracketClose, // Simbolo ]
		EndOfFile // Final de fichero
	};

	/// @brief Define un elemento dentro de un fichero de comandos EDENcm.
	struct EDENcm_Token {
		EDENcm_TokenType type;
		std::string text;
		int line;
		int column;
	};
}

#endif