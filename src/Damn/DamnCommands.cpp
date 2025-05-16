#include "DamnCommands.h"

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

