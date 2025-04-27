#include "ShotEvent.h"
#include "ISerializer.h"

ShotEvent::ShotEvent(int weapon, const int bulletID, const double posX, const double posY, const double posZ, const std::string info):
	TrackerEvent("Shot"),_weapon(weapon),_bulletID(bulletID),_weaponsInfo(info),_posX(posX), _posY(posY), _posZ(posZ)
{
}

ShotEvent::~ShotEvent()
{
}

void ShotEvent::serialize(ISerializer* serializer)
{
	TrackerEvent::serialize(serializer);
	serializer->serialize(_weapon, "weaponUsed");
	serializer->serialize(_bulletID, "bulletID");
	serializer->serialize(_weaponsInfo, "otherWeaponsInfo");
	serializer->serialize(_posX, "posX");
	serializer->serialize(_posY, "posY");
	serializer->serialize(_posZ, "posZ");
}
