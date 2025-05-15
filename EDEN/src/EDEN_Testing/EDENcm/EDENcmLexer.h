#ifndef EDENCM_LEXER_H
#define EDENCM_LEXER_H

#include "EDENcmToken.h"
#include <vector>

namespace eden_command {
	/// @brief Convierte un flujo de texto leido de un archivo .edencm a una cadena de Tokens que pueden ser interpretados.
	class EDENcm_Lexer {
	public:
		EDENcm_Lexer(const std::string& source);

		std::vector<EDENcm_Token> tokenize();

	private:

		std::string _source;
		size_t _pos = 0;
		int _line = 1;
		int _column = 1;

		void skipWhitespaceAndComments();

		EDENcm_Token nextToken();

		char peek(int offset = 0) const;

		char advance();

		bool isAtEnd() const;
	};
}

#endif