#pragma once
#include "TrackerEvent.h"

class PositionEvent : public TrackerEvent
{
public:
	PositionEvent(const bool stuck, double posX, const double posY, const double posZ);
	~PositionEvent();
	void serialize(ISerializer* serializer) override;

private:
	const bool _stuck;
	const double _posX;
	const double _posY;
	const double _posZ;
};

