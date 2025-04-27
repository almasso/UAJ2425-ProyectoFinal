#include "ShotCollisionEvent.h"
#include "ISerializer.h"

ShotCollisionEvent::ShotCollisionEvent(const int bulletID, const double posX, const double posY, const double posZ, const bool hasHitEnemy, const bool hasKillEnemy):TrackerEvent("ShotCollision"),
_bulletID(bulletID), _posX(posX), _posY(posY), _posZ(posZ),_hasHitEnemy(hasHitEnemy),_hasKillEnemy(hasKillEnemy)
{
}

ShotCollisionEvent::~ShotCollisionEvent()
{
}

void ShotCollisionEvent::serialize(ISerializer* serializer)
{
	TrackerEvent::serialize(serializer);
	serializer->serialize(_bulletID, "bulletID");
	serializer->serialize(_posX, "posX");
	serializer->serialize(_posY, "posY");
	serializer->serialize(_posZ, "posZ");
	serializer->serialize(_hasHitEnemy, "hasHitEnemy");
	serializer->serialize(_hasKillEnemy, "hasKillEnemy");
}
