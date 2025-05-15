#include "EDENcmStatements.h"
#include "../CommandManager.h"

void eden_command::EDENcm_FunctionCall::execute(eden_command::CommandManager& cm) {
	cm.setDebugLocation(line, column);
	cm.ExecuteFunction(name, args);
}

void eden_command::EDENcm_Loop::execute(eden_command::CommandManager& cm) {
	for (int i = 0; i < count; ++i) {
		cm.logDebugMessage("loop iter " + std::to_string(i + 1) + ": ");
		for (auto& stmt : body) {
			cm.setCurrentStatementIndex(i);
			stmt->execute(cm);
		}
	}
}

void eden_command::EDENcm_DebugOutput::execute(eden_command::CommandManager& cm) {
	cm.enableDebug();
	inner->execute(cm);
	cm.disableDebug();
}

void eden_command::EDENcm_DisableDebug::execute(eden_command::CommandManager& cm) {
	if(range) cm.setDisableRange(range->first, range->second);
	inner->execute(cm);
}