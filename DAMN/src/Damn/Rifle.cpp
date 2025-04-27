#include "Rifle.h"
#include "CAnimator.h"
#include "Entity.h"
#include<Transform.h>
#include<CMeshRenderer.h>
#include <CParticleEmitter.h>
#include "RayCast.h"
#include "Vector3.h"
#include <iostream>
#include "EnemyHealth.h"
#include "Entity.h"
#include <ComponentArguments.h>
#include "PhysicsManager.h"
#include "CAudioEmitter.h"

#include "Tracker.h"
#include "ShotCollisionEvent.h"

void damn::Rifle::Init(eden_script::ComponentArguments* args)
{
	WeaponComponent::Init(args);
	_rifleDamage = args->GetValueToInt("Damage");
}

void damn::Rifle::Start()
{
	_tr = _ent->GetComponent<eden_ec::CTransform>();
	_ent->GetComponent<eden_ec::CMeshRenderer>()->SetInvisible(true);
	WeaponComponent::Start();
}

bool damn::Rifle::Shoot(int _bulletsID)
{
	eden_ec::CTransform* _pTr = _player->GetComponent<eden_ec::CTransform>();
	if (_canShoot && _magazineAmmo > 0 && !isAnyAnimPlaying() && _player) {

		ShotCollisionEvent* collision;

		physics_wrapper::RayCastHitResult result;
		result = physics_manager::PhysicsManager::getInstance()->SingleHitRayCast(_pTr->GetPosition() + _pTr->GetForward()*-3, _pTr->GetPosition() + _pTr->GetForward() * -1000, true);
		if (result.hasHit) {
			if (result.entityHit->HasComponent("ENEMY_HEALTH")) {
				result.entityHit->GetComponent<damn::EnemyHealth>()->LoseHealth(_rifleDamage);

				collision = new ShotCollisionEvent(_bulletsID, result.rayHitLocationPoint.GetX(), result.rayHitLocationPoint.GetY(), result.rayHitLocationPoint.GetZ(), true, result.entityHit->GetComponent<damn::EnemyHealth>()->GetCurrentHealth() <= 0);
			}
			else {
				collision = new ShotCollisionEvent(_bulletsID, result.rayHitLocationPoint.GetX(), result.rayHitLocationPoint.GetY(), result.rayHitLocationPoint.GetZ(), false, false);
			}
		}
		else collision = new ShotCollisionEvent(_bulletsID, LONG_MAX, LONG_MAX, LONG_MAX, false, false);
		
		if (Tracker::Instance()) {
			Tracker::Instance()->TrackEvent(collision);
		}
		else delete collision;

		_canShoot = false;
		_magazineAmmo--;
		PlayShootAnim();
		return true;
	}
	else if (_magazineAmmo <= 0) {
		Reload();
	}
	return false;
}

void damn::Rifle::PlayIdleAnim()
{
	if (!_ent->GetComponent<eden_ec::CAnimator>()->IsPlaying("idleRifle")) {
		_ent->GetComponent<eden_ec::CAnimator>()->PlayAnim("idleRifle");
	}
}

void damn::Rifle::PlayShootAnim()
{
	if (!_ent->GetComponent<eden_ec::CAnimator>()->IsPlaying("shootRifle")) {
		_ent->GetComponent<eden_ec::CAnimator>()->PlayAnim("shootRifle");
	}
	if (_ent->HasComponent("AUDIO_EMITTER")) {
		_ent->GetComponent<eden_ec::CAudioEmitter>()->ChangeClip("rifleShoot.wav");
		_ent->GetComponent<eden_ec::CAudioEmitter>()->Play();
	}
}

void damn::Rifle::PlayReloadAnim()
{
	if (!_ent->GetComponent<eden_ec::CAnimator>()->IsPlaying("reloadRifle")) {
		_ent->GetComponent<eden_ec::CAnimator>()->PlayAnim("reloadRifle");
	}
	if (_ent->HasComponent("AUDIO_EMITTER")) {
		_ent->GetComponent<eden_ec::CAudioEmitter>()->ChangeClip("rifleReload.wav");
		_ent->GetComponent<eden_ec::CAudioEmitter>()->Play();
	}
}

bool damn::Rifle::isAnyAnimPlaying()
{
	return (_ent->GetComponent<eden_ec::CAnimator>()->IsPlaying("reloadRifle") || _ent->GetComponent<eden_ec::CAnimator>()->IsPlaying("shootRifle"));
}
