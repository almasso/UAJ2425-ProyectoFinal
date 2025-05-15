#ifndef EDEN_COMMANDS_H
#define EDEN_COMMANDS_H
#include <vector>
#include "EDENcm/EDENcmStatements.h"


namespace eden_command {
	class EDENCommands {
	public:
		static void InstantiateBlueprint(std::vector<Argument> params);
		static void ChangeScene(std::vector<Argument> params);
		static void Close(std::vector<Argument> params);
		static void print(std::vector<Argument> params);
	};
}
#endif //!EDEN_COMMANDS_H