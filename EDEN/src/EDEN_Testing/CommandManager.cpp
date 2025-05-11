#include "CommandManager.h"

eden_command::CommandManager* eden_command::CommandManager::getInstance() {
	return static_cast<CommandManager*>(Instance());
}