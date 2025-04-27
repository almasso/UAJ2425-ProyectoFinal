#include "ProgressionTracker.h"
#include "TrackerEvent.h"
#include "Persistence.h"

bool ProgressionTracker::accept(TrackerEvent* trackerEvent)
{
    std::string s = trackerEvent->GetEventType();
    if (isLevelStarted) {
        if (s == "LevelEnd") {
            isLevelStarted = false;
            return true;
        }
    }
    else {
        if (s == "LevelStart") {
            isLevelStarted = true;
            return true;
        }
    }
    return false;
}

bool ProgressionTracker::process(Persistence* persistence, TrackerEvent* trackerEvent)
{
    if (!persistence->QueueEvent(trackerEvent)) {
        return false;
    }
    return persistence->ForceFlush();
}
