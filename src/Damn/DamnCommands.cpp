#include "DamnCommands.h"
#include "SceneManager.h"
#include "HeatMapDrawer.h"
#include "MovementController.h"

void damn::DamnCommands::TrackerStartScene(std::vector<eden_command::Argument> args)
{
	if (args.size() != 1) return;

	if (Tracker::Instance()) {
		if (std::holds_alternative<int>(args[0])) {
			const auto& levelID = std::get<int>(args[0]);
			LevelStartEvent* levelStart = new LevelStartEvent(levelID);
			Tracker::Instance()->TrackEvent(levelStart);
		}
	}
}

void damn::DamnCommands::TrackerEndScene(std::vector<eden_command::Argument> args)
{
	if (Tracker::Instance()) {
		LevelEndEvent* levelEnd = new LevelEndEvent();
		Tracker::Instance()->TrackEvent(levelEnd);
	}
}

void damn::DamnCommands::ShowHeatMap(std::vector<eden_command::Argument> args)
{
	auto entities = eden::SceneManager::getInstance()->GetEntitiesWithComponent(HeatMapDrawer::GetID());
	if (entities.empty()) return;
	eden_ec::Entity* heatMapDrawer = entities[0];
	if (heatMapDrawer) {
		damn::HeatMapDrawer* heatMapComp = heatMapDrawer->GetComponent<damn::HeatMapDrawer>();
		if (heatMapComp) {
			if (std::holds_alternative<std::string>(args[0]) && std::holds_alternative<float>(args[1])) {
				heatMapComp->ReadData(std::get<std::string>(args[0]));
				heatMapComp->DiscretizeReadData(std::get<float>(args[1]));
				bool showStuck = true;
				if (std::holds_alternative<bool>(args[2])) {
					showStuck = std::get<bool>(args[2]);
				}
				float minSphereSize = 0.f;
				if (std::holds_alternative<float>(args[3])) {
					minSphereSize = std::get<float>(args[3]);
					if (minSphereSize < 0) minSphereSize = 0;
					else if (minSphereSize > 1) minSphereSize = 1;
				}
				heatMapComp->InstantiateHeatMapData(showStuck, minSphereSize);
			}
		}
	}
}

void damn::DamnCommands::EnableFlyMode(std::vector<eden_command::Argument> args)
{
	auto entities = eden::SceneManager::getInstance()->GetEntitiesWithComponent(MovementController::GetID());
	if (entities.empty()) return;
	eden_ec::Entity* controller = entities[0];
	if (controller) {
		damn::MovementController* movementController = controller->GetComponent<damn::MovementController>();
		if (movementController) {
			if (std::holds_alternative<bool>(args[0])) {
				movementController->EnableFlyMode(std::get<bool>(args[0]));
			}
		}
	}
}

