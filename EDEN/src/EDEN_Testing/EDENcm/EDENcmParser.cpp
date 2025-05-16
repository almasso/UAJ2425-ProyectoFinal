#include "EDENcmParser.h"
#include "EDENcmStatements.h"
#include "../CommandManager.h"

eden_command::EDENcm_Parser::EDENcm_Parser(const std::vector<eden_command::EDENcm_Token>& t) : _tokens(t) {}

const eden_command::EDENcm_Token& eden_command::EDENcm_Parser::peek(int offset) const {
	static const EDENcm_Token dummyToken{ EDENcm_TokenType::EndOfFile, "", 0, 0 };
	if (_tokens.empty() || _pos + offset >= _tokens.size()) return dummyToken;
	return _tokens[_pos + offset];
}

const eden_command::EDENcm_Token& eden_command::EDENcm_Parser::advance() {
	if (isAtEnd()) return peek();
	return _tokens[_pos++];
}

bool eden_command::EDENcm_Parser::match(eden_command::EDENcm_TokenType type) {
	if (peek().type == type) {
		advance();
		return true;
	}
	return false;
}

bool eden_command::EDENcm_Parser::isAtEnd() const {
	return peek().type == EDENcm_TokenType::EndOfFile;
}

bool eden_command::EDENcm_Parser::hadErrorParsing() const
{
	return _errorParsing;
}

std::vector<eden_command::EDENcm_Statement*> eden_command::EDENcm_Parser::parse() {
	std::vector<EDENcm_Statement*> statements;
	_errorParsing = false;
	while (!isAtEnd() && !_errorParsing) {
		auto statement = parseStatement();
		if (statement) statements.push_back(statement);
	}
	return statements;
}

eden_command::EDENcm_Statement* eden_command::EDENcm_Parser::parseStatement() {
	if (match(EDENcm_TokenType::KeywordLoop)) return parseLoop();
	if (match(EDENcm_TokenType::KeywordDebug)) return parseDebug();
	if (match(EDENcm_TokenType::KeywordDisable)) return parseDisable();
	if (match(EDENcm_TokenType::KeywordWait)) return parseWait();
	return parseFunctionCall();
}

eden_command::EDENcm_Statement* eden_command::EDENcm_Parser::parseFunctionCall() {
	const EDENcm_Token& tk = advance();
	std::string name = tk.text;
	
	if (!match(EDENcm_TokenType::ParenOpen)) {
		ErrorParsing();
	}

	std::vector<Argument> args;
	bool parenClose = false;
	bool comma = true;
	while (!(parenClose = match(EDENcm_TokenType::ParenClose)) && !isAtEnd()) {
		if (!comma) {
			ErrorParsing();
		}
		
		const EDENcm_Token& t = peek();
		
		if (t.type == EDENcm_TokenType::Identifier && (t.text == "true" || t.text == "false")) {
			args.push_back(Argument(t.text == "true"));
			advance();
		}
		else if (t.type == EDENcm_TokenType::Identifier && t.text == "vec3") {
			advance();
			float x, y, z = 0;
			try {
				if (!match(EDENcm_TokenType::ParenOpen)) {
					ErrorParsing();
				}
				x = std::stof(advance().text);
				if (!match(EDENcm_TokenType::Comma)) {
					ErrorParsing();
				}
				y = std::stof(advance().text);
				if (!match(EDENcm_TokenType::Comma)) {
					ErrorParsing();
				}
				z = std::stof(advance().text);
				if (!match(EDENcm_TokenType::ParenClose)) {
					ErrorParsing();
				}
			}
			catch (std::exception e) {
				ErrorParsing();
			}
			args.push_back(Argument(eden_utils::Vector3{x, y, z}));
		}
		else if (t.type == EDENcm_TokenType::String) {
			args.push_back(t.text);
			advance();
		}
		else if (t.type == EDENcm_TokenType::Number) {
			std::string numStr = t.text;
			try {
				if (numStr.find('.') != std::string::npos) {
					args.push_back(Argument(std::stof(numStr)));
				}
				else {
					args.push_back(Argument(std::stoi(numStr)));
				}
			}
			catch (std::exception e) {
				ErrorParsing();
			}
			advance();
		}
		else {
			CommandManager::getInstance()->logDebugMessage("Unexpected token: " + t.text, true);
			ErrorParsing();
		}

		comma = match(EDENcm_TokenType::Comma);
	}

	if (!parenClose) {
		ErrorParsing();
	}

	match(EDENcm_TokenType::Semicolon);
	auto fn = new EDENcm_FunctionCall();
	fn->name = name;
	fn->args = args;
	fn->line = tk.line;
	fn->column = tk.column;
	return fn;
}

eden_command::EDENcm_Statement* eden_command::EDENcm_Parser::parseLoop() {
	int count = 0;
	try {
		count = std::stoi(advance().text);
	}
	catch (std::exception e) {
		ErrorParsing();
	}
	
	if (!match(EDENcm_TokenType::BraceOpen)) {
		ErrorParsing();
	}

	bool braceClose = false;
	std::vector<EDENcm_Statement*> body;
	while (!(braceClose = match(EDENcm_TokenType::BraceClose)) && !isAtEnd()) {
		body.push_back(parseStatement());
	}

	if (!braceClose) {
		for (auto statement : body) {
			delete statement;
		}
		ErrorParsing();
	}

	match(EDENcm_TokenType::Semicolon);

	auto loop = new EDENcm_Loop();
	loop->count = count;
	loop->body = body;
	return loop;
}

eden_command::EDENcm_Statement* eden_command::EDENcm_Parser::parseDebug() {
	if (!match(EDENcm_TokenType::SymbolLeftShift)) {
		ErrorParsing();
	}

	auto dbg = new EDENcm_DebugOutput();
	dbg->inner = parseStatement();
	return dbg;
}

eden_command::EDENcm_Statement* eden_command::EDENcm_Parser::parseDisable() {
	auto dis = new EDENcm_DisableDebug();
	if (match(EDENcm_TokenType::BracketOpen)) {
		int from = 0;
		int to = 0;
		try {
			from = std::stoi(advance().text);
			if (!match(EDENcm_TokenType::Colon)) {
				delete dis;
				ErrorParsing();
			}
			to = std::stoi(advance().text);
			if (!match(EDENcm_TokenType::BracketClose)) {
				delete dis;
				ErrorParsing();
			}
		}
		catch (std::exception e) {
			delete dis;
			ErrorParsing();
		}
		
		dis->range = std::make_pair(from, to);
	}
	if (!match(EDENcm_TokenType::SymbolRightShift)) {
		delete dis;
		ErrorParsing();
	}
	dis->inner = parseStatement();
	return dis;
}

eden_command::EDENcm_Statement* eden_command::EDENcm_Parser::parseWait() {
	float seconds = 0.0f;
	try {
		seconds = std::stof(advance().text);
	}
	catch (std::exception e) {
		ErrorParsing();
	}
	std::string unit = advance().text;
	if (unit == "s") seconds *= 1.0f;
	else if (unit == "ms") seconds /= 1000.0f;
	else ErrorParsing();

	match(EDENcm_TokenType::Semicolon);

	auto waitStmt = new EDENcm_Wait();
	waitStmt->waitSeconds = seconds;
	return waitStmt;
}