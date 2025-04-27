#pragma once
#include "ITrackerAsset.h"
#include <unordered_set>
#include <string>

class GameEventTracker : public ITrackerAsset
{
public:
	~GameEventTracker() = default;
	bool accept(TrackerEvent* trackerEvent) override;
	bool process(Persistence* persistence, TrackerEvent* trackerEvent) override;
private:
	std::unordered_set<std::string> _gameEvents = { "Shot", "ShotCollision" };
};
