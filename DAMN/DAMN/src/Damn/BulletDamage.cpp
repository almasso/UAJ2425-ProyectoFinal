#include "BulletDamage.h"

#include "Entity.h"
#include <ComponentArguments.h>
#include <Transform.h>
#include "BulletEnemyDamage.h"

#include "Tracker.h"
#include "ShotCollisionEvent.h"
#include "ProjectileMovement.h"

void damn::BulletDamage::Init(eden_script::ComponentArguments* args)
{
	_damage = args->GetValueToInt("Damage");
}

void damn::BulletDamage::Update(float deltaTime)
{
	if (_timeAlive >= _lifeTime) {
		if (_ent->HasComponent<BulletEnemyDamage>()) {
			ShotCollisionEvent* collision = new ShotCollisionEvent(_ent->GetComponent<ProjectileMovement>()->bulletID,
				_ent->GetComponent<eden_ec::CTransform>()->GetPosition().GetX(), _ent->GetComponent<eden_ec::CTransform>()->GetPosition().GetY(),
				_ent->GetComponent<eden_ec::CTransform>()->GetPosition().GetZ(), false,false);

			if (Tracker::Instance()) {
				Tracker::Instance()->TrackEvent(collision);
			}
			else delete collision;
		}
		_ent->SetAlive(false);
	}
	else _timeAlive += deltaTime;
}
