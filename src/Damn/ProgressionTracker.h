#pragma once
#include "ITrackerAsset.h"

class ProgressionTracker : public ITrackerAsset
{
public:
	~ProgressionTracker() = default;
	bool accept(TrackerEvent* trackerEvent) override;
	bool process(Persistence* persistence, TrackerEvent* trackerEvent) override;
private:
	bool isLevelStarted = false;
};

