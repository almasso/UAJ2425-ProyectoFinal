#include "LevelStartEvent.h"
#include "ISerializer.h"

LevelStartEvent::LevelStartEvent(const int level) : TrackerEvent("LevelStart"), _level(level)
{
}

LevelStartEvent::~LevelStartEvent()
{
}

void LevelStartEvent::serialize(ISerializer* serializer)
{
	TrackerEvent::serialize(serializer);
	serializer->serialize(_level, "levelStarted");
}
