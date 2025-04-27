#include "GameEventTracker.h"
#include "Persistence.h"

bool GameEventTracker::accept(TrackerEvent* trackerEvent)
{
    return _gameEvents.contains(trackerEvent->GetEventType());
}

bool GameEventTracker::process(Persistence* persistence, TrackerEvent* trackerEvent)
{
    return persistence->QueueEvent(trackerEvent);
}
