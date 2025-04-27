#pragma once
#include "TrackerEvent.h"

class ShotEvent: public TrackerEvent
{
public:
	ShotEvent(int weapon, const int bulletID,const double posX, const double posY, const double posZ, const std::string info);
	~ShotEvent();
	void serialize(ISerializer* serializer) override;

private:
	int _weapon;
	const int _bulletID;
	const std::string _weaponsInfo;
	const double _posX;
	const double _posY;
	const double _posZ;
};

