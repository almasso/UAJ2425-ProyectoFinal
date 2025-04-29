#include "PositionEvent.h"
#include "ISerializer.h"

PositionEvent::PositionEvent(const bool stuck, double posX, const double posY, const double posZ) :
	TrackerEvent("Position"), _stuck(stuck),_posX(posX), _posY(posY), _posZ(posZ)
{
}

PositionEvent::~PositionEvent()
{
}

void PositionEvent::serialize(ISerializer* serializer)
{
	TrackerEvent::serialize(serializer);
	serializer->serialize(_stuck, "isStuck");
	serializer->serialize(_posX, "posX");
	serializer->serialize(_posY, "posY");
	serializer->serialize(_posZ, "posZ");
}