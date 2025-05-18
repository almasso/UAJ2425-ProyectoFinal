#include "MovementController.h"
#include <Entity.h>
#include <ComponentArguments.h>
#include <iostream>

void damn::MovementController::Init(eden_script::ComponentArguments* args)
{
	_speed = args->GetValueToFloat("Speed");
}

void damn::MovementController::Start()
{
	_rigidBody = _ent->GetComponent<eden_ec::CRigidBody>();
}

void damn::MovementController::Update(float deltaTime)
{
	if (_rigidBody) {
		eden_utils::Vector3 vel = _rigidBody->GetLinearVelocity();
		if (_flyModeEnabled) {
			vel = eden_utils::Vector3(_direction.GetX() * _speed, _direction.GetY() * _speed, _direction.GetZ() * _speed);
		}
		else {
			vel = eden_utils::Vector3(_direction.GetX() * _speed, vel.GetY(), _direction.GetZ() * _speed);
		}
		_rigidBody->SetLinealVelocity(vel);
	}
}

void damn::MovementController::SetDirection(eden_utils::Vector3 newDir)
{
	_direction = newDir.Normalized();
}

void damn::MovementController::EnableFlyMode(bool v)
{
	_flyModeEnabled = v;
}
