#include "BulletEnemyDamage.h"

#include <ScriptManager.h>
#include <LuaManager.h>
#include <Entity.h>
#include <Transform.h>

#include "Health.h"
#include "EnemyHealth.h"

#include "Tracker.h"
#include "ShotCollisionEvent.h"
#include "ProjectileMovement.h"

void damn::BulletEnemyDamage::Start()
{
	eden_script::LuaManager* _luaMngr = eden_script::ScriptManager::getInstance()->GetLuaManager();
	_luaMngr->Regist(*this, "BulletHitsEnemy", &damn::BulletEnemyDamage::HasHitEnemy, "HasHitEnemy", this);
	_luaMngr->SetGlobal(*this, "BulletHitsEnemy");
	_luaMngr = nullptr;
}

void damn::BulletEnemyDamage::HasHitEnemy()
{
	eden_ec::Entity* _other = luabridge::getGlobal(eden_script::ScriptManager::getInstance()->GetLuaManager()->GetLuaState(), "other");
	eden_ec::Entity* _self = luabridge::getGlobal(eden_script::ScriptManager::getInstance()->GetLuaManager()->GetLuaState(), "self");
	damn::Health* _healthComponent = nullptr;
	eden_ec::CTransform* tr = _self->GetComponent<eden_ec::CTransform>();
	
	if (_other->HasComponent("ENEMY_HEALTH")) {
		_healthComponent = _other->GetComponent<EnemyHealth>();
		_healthComponent->LoseHealth(_self->GetComponent<BulletEnemyDamage>()->_damage);

		ShotCollisionEvent* collision = new ShotCollisionEvent(_self->GetComponent<ProjectileMovement>()->bulletID,
			tr->GetPosition().GetX(), tr->GetPosition().GetY(), tr->GetPosition().GetZ(), true, _healthComponent->GetCurrentHealth() <= 0);

		if (Tracker::Instance()) {
			Tracker::Instance()->TrackEvent(collision);
		}
		else delete collision;
		_self->SetAlive(false);
	}
	else if (!_other->HasComponent("BULLET_ENEMY_DAMAGE") && !_other->HasComponent("BULLET_PLAYER_DAMAGE")) {

		ShotCollisionEvent* collision = new ShotCollisionEvent(_self->GetComponent<ProjectileMovement>()->bulletID,
			tr->GetPosition().GetX(), tr->GetPosition().GetY(), tr->GetPosition().GetZ(), false, false);
	
		if (Tracker::Instance()) {
			Tracker::Instance()->TrackEvent(collision);
		}
		else delete collision;
		_self->SetAlive(false);
	}
}
