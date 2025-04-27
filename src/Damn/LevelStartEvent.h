#pragma once
#include "TrackerEvent.h"
class LevelStartEvent : public TrackerEvent
{
public:
	LevelStartEvent(const int level);
	~LevelStartEvent();
	void serialize(ISerializer* serializer) override;

private:
	const int _level;
};

