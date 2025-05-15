#include "EDENcmStatements.h"
#include "../CommandManager.h"

void eden_command::EDENcm_FunctionCall::execute(eden_command::CommandManager& cm) {
	cm.setDebugLocation(line, column);
	cm.ExecuteFunction(name, args);
}

void eden_command::EDENcm_Loop::execute(eden_command::CommandManager& cm) {
	if (finished) return;
	if (cm.isWaiting()) return;

	if (currentIteration < count) {
		if (!sent) {
			cm.logDebugMessage("loop iter " + std::to_string(currentIteration + 1) + ": ");
			sent = true;
		}
		if (currentStatement < body.size()) {
			if (!cm.isWaiting()) {
				cm.setCurrentStatementIndex(currentIteration);
				body[currentStatement]->execute(cm);
				currentStatement++;
			}
		}
		else {
			currentIteration++;
			currentStatement = 0;
			sent = false;
		}
	}
	else {
		finished = true;
	}
}

bool eden_command::EDENcm_Loop::isFinished() const {
	return finished;
}

eden_command::EDENcm_Loop::~EDENcm_Loop() {
	for (auto& stmt : body) {
		delete stmt;
	}
}

void eden_command::EDENcm_DebugOutput::execute(eden_command::CommandManager& cm) {
	cm.enableDebug();
	inner->execute(cm);
	cm.disableDebug();
}

bool eden_command::EDENcm_DebugOutput::isFinished() const {
	return inner->isFinished();
}

eden_command::EDENcm_DebugOutput::~EDENcm_DebugOutput() {
	delete inner;
}

void eden_command::EDENcm_DisableDebug::execute(eden_command::CommandManager& cm) {
	if(range) cm.setDisableRange(range->first, range->second);
	inner->execute(cm);
	if (range) cm.setDisableRange(-1, -1);
}

bool eden_command::EDENcm_DisableDebug::isFinished() const {
	return inner->isFinished();
}

eden_command::EDENcm_DisableDebug::~EDENcm_DisableDebug() {
	delete inner;
}

void eden_command::EDENcm_Wait::execute(eden_command::CommandManager& cm) {
	if(!cm.isWaiting()) cm.startWait(waitSeconds);
}