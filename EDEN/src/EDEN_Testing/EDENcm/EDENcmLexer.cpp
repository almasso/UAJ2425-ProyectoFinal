#include "EDENcmLexer.h"
#include "../CommandManager.h"

eden_command::EDENcm_Lexer::EDENcm_Lexer(const std::string& src) : _source(src) {}

char eden_command::EDENcm_Lexer::peek(int offset) const {
	if (_pos + offset >= _source.size()) return '\0';
	return _source[_pos + offset];
}

char eden_command::EDENcm_Lexer::advance() {
	char c = peek();
	++_pos;
	if (c == '\n') {
		++_line;
		_column = 1;
	}
	else {
		++_column;
	}
	return c;
}

bool eden_command::EDENcm_Lexer::isAtEnd() const {
	return _pos >= _source.size();
}

void eden_command::EDENcm_Lexer::skipWhitespaceAndComments() {
	while (!isAtEnd()) { // Ejecutamos mientras no estemos en el final del archivo
		if (std::isspace(peek())) { // Si estamos en un espacio...
			advance(); // ... avanzamos caracter
		}
		else if (peek() == '/' && peek(1) == '/') { // Si estamos en el caso de // ...
			while (!isAtEnd() && peek() != '\n') advance(); // ... avanzamos hasta el final de linea
		}
		else if (peek() == '/' && peek(1) == '*') { // Si estamos en el caso de /* ...
			advance(); // Avanzamos los dos caracteres
			advance();
			while (!(peek() == '*' && peek(1) == '/') && !isAtEnd()) advance(); // ... y buscamos */
			if (!isAtEnd()) { // Si queda mas archivo avanzamos el * y el / ...
				advance();
				advance();
			}
			else break; // Y si no, paramos.
		}
		else break;
	}
}

eden_command::EDENcm_Token eden_command::EDENcm_Lexer::nextToken() {
	skipWhitespaceAndComments();
	if (isAtEnd()) return { EDENcm_TokenType::EndOfFile, "", _line, _column };

	char c = advance();
	if (std::isalpha(c) || c == '_') {
		std::string ident(1, c);
		while (std::isalnum(peek()) || peek() == '_') ident += advance();
		if (ident == "loop") return { EDENcm_TokenType::KeywordLoop, ident, _line, _column };
		if (ident == "debug") return { EDENcm_TokenType::KeywordDebug, ident, _line, _column };
		if (ident == "disable") return { EDENcm_TokenType::KeywordDisable, ident, _line, _column };
		if (ident == "wait") return { EDENcm_TokenType::KeywordWait, ident, _line, _column };
		return { EDENcm_TokenType::Identifier, ident, _line, _column };
	}

	if (std::isdigit(c)) {
		std::string num(1, c);
		bool hasDot = false;
		while (std::isdigit(peek()) || (!hasDot && peek() == '.')) {
			if (peek() == '.') hasDot = true;
			num += advance();
		}
		return { EDENcm_TokenType::Number, num, _line, _column };
	}

	if (c == '"') {
		std::string str;
		while (peek() != '"' && !isAtEnd()) str += advance();
		if (!isAtEnd()) advance();
		return { EDENcm_TokenType::String, str, _line, _column };
	}

	switch (c) {
		case '<': {
			if (peek() == '<') {
				advance();
				return { EDENcm_TokenType::SymbolLeftShift, "<<", _line, _column };
			}
		} break;
		case '>': {
			if (peek() == '>') {
				advance();
				return { EDENcm_TokenType::SymbolRightShift, ">>", _line, _column };
			}
		} break;
		case ',': {
			return { EDENcm_TokenType::Comma, ",", _line, _column };
		} break;
		case ';': {
			return { EDENcm_TokenType::Semicolon, ";", _line, _column };
		} break;
		case ':': {
			return { EDENcm_TokenType::Colon, ":", _line, _column };
		} break;
		case '(': {
			return { EDENcm_TokenType::ParenOpen, "(", _line, _column };
		} break;
		case ')': {
			return { EDENcm_TokenType::ParenClose, ")", _line, _column };
		} break;
		case '{': {
			return { EDENcm_TokenType::BraceOpen, "{", _line, _column };
		} break;
		case '}': {
			return { EDENcm_TokenType::BraceClose, "}", _line, _column };
		} break;
		case '[': {
			return { EDENcm_TokenType::BracketOpen, "[", _line, _column };
		} break;
		case ']': {
			return { EDENcm_TokenType::BracketClose, "]", _line, _column };
		} break;
	}

	CommandManager::getInstance()->setDebugLocation(_line, _column);
	CommandManager::getInstance()->logDebugMessage("Syntax ERROR: unexpected character '" + std::string(1, c) + "'", true);

	return { EDENcm_TokenType::EndOfFile, "", _line, _column };
}

std::vector<eden_command::EDENcm_Token> eden_command::EDENcm_Lexer::tokenize() {
	std::vector<EDENcm_Token> tokens;
	while (true) {
		EDENcm_Token t = nextToken();
		tokens.push_back(t);
		if (t.type == EDENcm_TokenType::EndOfFile) break;
	}
	return tokens;
}