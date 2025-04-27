#pragma once
#include "TrackerEvent.h"

class ShotCollisionEvent : public TrackerEvent
{
public:
	ShotCollisionEvent(const int bulletID, const double posX, const double posY, const double posZ,const bool hasHitEnemy,const bool hasKillEnemy);
	~ShotCollisionEvent();
	void serialize(ISerializer* serializer) override;

private:
	const int _bulletID;
	const bool _hasHitEnemy;
	const bool _hasKillEnemy;
	const double _posX;
	const double _posY;
	const double _posZ;
};
