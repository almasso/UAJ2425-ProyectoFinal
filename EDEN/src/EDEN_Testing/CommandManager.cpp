#include "CommandManager.h"
#include <ResourcesManager.h>
#include <filesystem>
#include <fstream>
#include <sstream>
#include "EDENcm/EDENcmLexer.h"
#include "EDENcm/EDENcmParser.h"
#include "EDENcm/EDENcmStatements.h"

eden_command::CommandManager* eden_command::CommandManager::getInstance() {
	return static_cast<CommandManager*>(Instance());
}

eden_command::CommandManager::~CommandManager() {
	for (auto ctx : _activeScripts) {
		for (auto stmt : ctx.statements) delete stmt;
	}
	closeDebugFile();
}

void eden_command::CommandManager::ExecuteScripts() {
	std::set<std::string> commandRoutes = eden_resources::ResourcesManager::Instance()->GetRoutesCommands();
	std::set<std::string> commands = eden_resources::ResourcesManager::Instance()->GetCommands();
	auto ot = commandRoutes.begin();

	for (auto it = commands.begin(); it != commands.end(); ++it) {
		std::filesystem::path fp = *it;
		std::ifstream file(*ot);
		std::stringstream buffer;
		buffer << file.rdbuf();
		
		EDENcm_Lexer lexer(buffer.str());
		EDENcm_Parser parser(lexer.tokenize());
		auto statements = parser.parse();

		_activeScripts.push_back(ScriptExecutionContext{ 
			.statements = std::move(statements), 
			.currentStatementIndex = 0, 
			.debugName = fp.stem().string(), 
			.finished = false }
			);
		
		++ot;
	}
}

void eden_command::CommandManager::openDebugFile(const std::string& scriptFilename) {
	_outputFilepath = scriptFilename + ".ecmout";
	_debugFile.open(_outputFilepath, std::ios::out);
}

void eden_command::CommandManager::closeDebugFile() {
	if (_debugFile.is_open()) _debugFile.close();
}

void eden_command::CommandManager::setDebugLocation(int line, int column) {
	_debugLine = line;
	_debugColumn = column;
}

void eden_command::CommandManager::logDebugMessage(const std::string& message, bool isError) {
	if (!_debugEnabled) return;
	if (!_debugFile.is_open()) return;

	if (_disabledRange) {
		int from = _disabledRange->first;
		int to = _disabledRange->second;
		if (_currentStatementIndex >= from && _currentStatementIndex <= to) return;
	}

	if (isError) _debugFile << "ERROR @ ";
	_debugFile << "[Line " << _debugLine << " : Column " << _debugColumn << "] : " << message;
	_debugFile << std::endl;
}

void eden_command::CommandManager::enableDebug() {
	_debugEnabled = true;
}

void eden_command::CommandManager::disableDebug() {
	_debugEnabled = false;
}

void eden_command::CommandManager::startWait(float seconds) {
	_waitTime = seconds;
}

void eden_command::CommandManager::setDisableRange(int from, int to) {
	_disabledRange = std::make_pair(from, to);
}

void eden_command::CommandManager::Update(float dT) {
	_time += dT;

	if (_waitTime > 0.0f) {
		_waitTime -= dT;
		if (_waitTime > 0.0f) return;
		_waitTime = 0.0f;
	}

	for (auto& ctx : _activeScripts) {
		if (ctx.finished) continue;

		if(!_debugFile.is_open()) openDebugFile(ctx.debugName);

		if (ctx.currentStatementIndex < ctx.statements.size()) {
			auto* stmt = ctx.statements[ctx.currentStatementIndex];
			stmt->execute(*this);
			if (stmt->isFinished()) ctx.currentStatementIndex++;
		}
		else {
			ctx.finished = true;
			for (auto* stmt : ctx.statements) delete stmt;
			ctx.statements.clear();
			closeDebugFile();
		}
	}

	_debugLine = 0;
	_debugColumn = 0;
	_currentStatementIndex = 0;
}

void eden_command::CommandManager::setCurrentStatementIndex(int index) {
	_currentStatementIndex = index;
}

bool eden_command::CommandManager::isWaiting() const {
	return _waitTime > 0.0f;
}