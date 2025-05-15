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

std::vector<eden_command::EDENcm_Statement*> eden_command::EDENcm_Parser::parse() {
	std::vector<EDENcm_Statement*> statements;
	while (!isAtEnd()) {
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
	
	match(EDENcm_TokenType::ParenOpen);
	std::vector<Argument> args;
	while (!match(EDENcm_TokenType::ParenClose)) {
		const EDENcm_Token& t = peek();
		
		if (t.type == EDENcm_TokenType::Identifier && (t.text == "true" || t.text == "false")) {
			args.push_back(Argument(t.text == "true"));
			advance();
		}
		else if (t.type == EDENcm_TokenType::Identifier && t.text == "vec3") {
			advance();
			match(EDENcm_TokenType::ParenOpen);
			float x = std::stof(advance().text);
			match(EDENcm_TokenType::Comma);
			float y = std::stof(advance().text);
			match(EDENcm_TokenType::Comma);
			float z = std::stof(advance().text);
			match(EDENcm_TokenType::ParenClose);
			args.push_back(Argument(eden_utils::Vector3{x, y, z}));
		}
		else if (t.type == EDENcm_TokenType::String) {
			args.push_back(t.text);
			advance();
		}
		else if (t.type == EDENcm_TokenType::Number) {
			std::string numStr = t.text;
			if (numStr.find('.') != std::string::npos) {
				args.push_back(Argument(std::stof(numStr)));
			}
			else {
				args.push_back(Argument(std::stoi(numStr)));
			}
			advance();
		}
		else {
			CommandManager::getInstance()->logDebugMessage("Unexpected token: " + t.text, true);
			advance();
		}

		match(EDENcm_TokenType::Comma);
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
	int count = std::stoi(advance().text);
	match(EDENcm_TokenType::BraceOpen);
	std::vector<EDENcm_Statement*> body;
	while (!match(EDENcm_TokenType::BraceClose) && !isAtEnd()) {
		body.push_back(parseStatement());
	}
	match(EDENcm_TokenType::Semicolon);
	auto loop = new EDENcm_Loop();
	loop->count = count;
	loop->body = body;
	return loop;
}

eden_command::EDENcm_Statement* eden_command::EDENcm_Parser::parseDebug() {
	match(EDENcm_TokenType::SymbolLeftShift);
	auto dbg = new EDENcm_DebugOutput();
	dbg->inner = parseStatement();
	return dbg;
}

eden_command::EDENcm_Statement* eden_command::EDENcm_Parser::parseDisable() {
	auto dis = new EDENcm_DisableDebug();
	if (match(EDENcm_TokenType::BracketOpen)) {
		int from = std::stoi(advance().text);
		match(EDENcm_TokenType::Colon);
		int to = std::stoi(advance().text);
		match(EDENcm_TokenType::BracketClose);
		dis->range = std::make_pair(from, to);
	}
	match(EDENcm_TokenType::SymbolRightShift);
	dis->inner = parseStatement();
	return dis;
}

eden_command::EDENcm_Statement* eden_command::EDENcm_Parser::parseWait() {
	float seconds = 0.0f;
	seconds = std::stof(advance().text);
	std::string unit = advance().text;
	if (unit == "s") seconds *= 1.0f;
	else if (unit == "ms") seconds /= 1000.0f;
	else seconds = 0.0f;
	match(EDENcm_TokenType::Semicolon);

	auto waitStmt = new EDENcm_Wait();
	waitStmt->waitSeconds = seconds;
	return waitStmt;
}