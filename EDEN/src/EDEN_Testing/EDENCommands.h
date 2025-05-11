#ifndef EDEN_COMMANDS_H
#define EDEN_COMMANDS_H
#include <vector>
#include <any>


namespace eden_command {
	class EDENCommands
	{
	public:
		static void InstantiateBlueprint(std::vector<std::any> params);
		static void ChangeScene(std::vector<std::any> params);
	};
}
#endif //!EDEN_COMMANDS_H