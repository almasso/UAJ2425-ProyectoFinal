#include "EDENCommands.h"
#include "SceneManager.h"
#include "Vector3.h"

void eden_command::EDENCommands::InstantiateBlueprint(std::vector<std::any> params)
{
	if (params.size() <= 0) return;

	if (params[0].has_value() && params[0].type() == typeid(std::string)) {
		if (params.size() == 2 && params[1].has_value() && params[1].type() == typeid(eden_utils::Vector3)) {
			eden::SceneManager::Instance()->InstantiateBlueprint(std::any_cast<const std::string&>(params[0]), std::any_cast<const eden_utils::Vector3&>(params[1]));
		}
		else {
			eden::SceneManager::Instance()->InstantiateBlueprint(std::any_cast<const std::string&>(params[0]), eden_utils::Vector3(0,0,0));
		}
	}
}

void eden_command::EDENCommands::ChangeScene(std::vector<std::any> params)
{
	if (params.size() <= 0) return;

	if (params[0].has_value() && params[0].type() == typeid(std::string)) {
		eden::SceneManager::Instance()->ChangeScene(std::any_cast<const std::string&>(params[0]));
	}
}
