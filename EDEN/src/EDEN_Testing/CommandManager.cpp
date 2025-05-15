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

void eden_command::CommandManager::ExecuteScripts() {
	std::set<std::string> commandRoutes = eden_resources::ResourcesManager::Instance()->GetRoutesCommands();
	std::set<std::string> commands = eden_resources::ResourcesManager::Instance()->GetCommands();
	auto ot = commandRoutes.begin();
	for (auto it = commands.begin(); it != commands.end(); ++it) {
		std::filesystem::path fp = *it;
		openDebugFile(fp.stem().string());
		std::ifstream file(*ot);
		std::stringstream buffer;
		buffer << file.rdbuf();
		
		EDENcm_Lexer lexer(buffer.str());
		EDENcm_Parser parser(lexer.tokenize());
		auto statements = parser.parse();
		
		for (auto& stmt : statements) {
			stmt->execute(*getInstance());
			delete stmt;
		}

		closeDebugFile();
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

void eden_command::CommandManager::setDisableRange(int from, int to) {
	_disabledRange = std::make_pair(from, to);
}

void eden_command::CommandManager::setCurrentStatementIndex(int index) {
	_currentStatementIndex = index;
}