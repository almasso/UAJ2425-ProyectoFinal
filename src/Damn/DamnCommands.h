#pragma once
#include <vector>
#include "EDENcm/EDENcmStatements.h"
#include "Tracker.h"
#include "LevelStartEvent.h"
#include "LevelEndEvent.h"

namespace damn {
	class DamnCommands
	{
	public:
		static void TrackerStartScene(std::vector<eden_command::Argument> args);

		static void TrackerEndScene(std::vector<eden_command::Argument> args);
	};
}

