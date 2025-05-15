#include "EDENCommands.h"
#include "SceneManager.h"
#include "Vector3.h"
#include <iostream>
#include "CommandManager.h"

void eden_command::EDENCommands::InstantiateBlueprint(std::vector<Argument> params)
{
	if (params.size() <= 0) { 
		CommandManager::getInstance()->logDebugMessage("At InstantiateBlueprint: missing arguments (string, [vec3] expected).", true);
		return; 
	}

	if (std::holds_alternative<std::string>(params[0])) {
		const std::string& blueprintName = std::get<std::string>(params[0]);

		eden_utils::Vector3 position{ 0,0,0 };

		if (std::holds_alternative<eden_utils::Vector3>(params[1])) {
			position = std::get<eden_utils::Vector3>(params[1]);
		}
		

		eden::SceneManager::Instance()->InstantiateBlueprint(blueprintName, position);
		CommandManager::getInstance()->logDebugMessage("At InstantiateBlueprint: instantiation of '" +
			blueprintName + "' at (" + 
			std::to_string(position.GetX()) + "," +
			std::to_string(position.GetY()) + "," +
			std::to_string(position.GetZ()) + ") was successful.");
		return;
	}
	else {
		CommandManager::getInstance()->logDebugMessage("At InstantiateBlueprint: 'blueprint' value is not of type string", true);
	}
}

void eden_command::EDENCommands::ChangeScene(std::vector<Argument> params)
{
	if (params.size() <= 0) {
		CommandManager::getInstance()->logDebugMessage("At ChangeScene: missing arguments (string expected).", true);
		return;
	}

	if (std::holds_alternative<std::string>(params[0])) {
		const auto& sceneID = std::get<std::string>(params[0]);
		eden::SceneManager::Instance()->ChangeScene(sceneID);
		CommandManager::getInstance()->logDebugMessage("At ChangeScene: changed scene to '" + sceneID + "' successfully.");
	}
	else {
		CommandManager::getInstance()->logDebugMessage("At ChangeScene: 'sceneID' value is not of type string", true);
	}
}

void eden_command::EDENCommands::print(std::vector<Argument> params) {
	if (params.size() <= 0) {
		CommandManager::getInstance()->logDebugMessage("At print: missing arguments (string expected).", true);
		return;
	}
	
	if (std::holds_alternative<std::string>(params[0])) {
		const auto& msg = std::get<std::string>(params[0]);
		std::cout << msg<< std::endl;
		CommandManager::getInstance()->logDebugMessage("At print: message '" + msg + "' printed sucessfully.");
	}
	else {
		CommandManager::getInstance()->logDebugMessage("At print: 'message' value is not of type string", true);
	}
}
