#ifndef EDENCM_PARSER_H
#define EDENCM_PARSER_H

#include "EDENcmToken.h"
#include "EDENcmStatements.h"
#include <vector>
#include <exception>


#define ErrorParsing() { _errorParsing = true; return nullptr; };

namespace eden_command {
	/// @brief Toma un vector de Tokens generado por el Lexer para poder hacer el arbol de llamadas de sentencias (statements).
	class EDENcm_Parser {
	public:
		EDENcm_Parser(const std::vector<EDENcm_Token>& tokens);

		EDEN_API std::vector<EDENcm_Statement*> parse();

		bool hadErrorParsing() const;
	private:
		std::vector<EDENcm_Token> _tokens;

		size_t _pos = 0;

		bool _errorParsing = false;

		EDENcm_Statement* parseStatement();

		EDENcm_Statement* parseFunctionCall();

		EDENcm_Statement* parseLoop();

		EDENcm_Statement* parseDebug();

		EDENcm_Statement* parseDisable();

		EDENcm_Statement* parseWait();

		const EDENcm_Token& peek(int offset = 0) const;

		const EDENcm_Token& advance();

		bool match(EDENcm_TokenType type);

		bool isAtEnd() const;
	};
}

#endif