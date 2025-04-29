#include "BootMovement.h"
#include<InputManager.h>
#include "CameraMovement.h"
#include "SceneManager.h"
#include "GameManager.h"
#include <Entity.h>
#include <ComponentArguments.h>
#include <iostream>
#include "PositionEvent.h"
#include "FilePersistence.h"
#include "Tracker.h"


void damn::BootMovement::Init(eden_script::ComponentArguments* args)
{
	_speed = args->GetValueToFloat("Speed");
}

void damn::BootMovement::Start()
{
	_rigidBody = _ent->GetComponent<eden_ec::CRigidBody>();
	_transform = _ent->GetComponent<eden_ec::CTransform>();
	_cameraMovement = _ent->GetComponent<damn::CameraMovement>();
	_inputManager = eden_input::InputManager::getInstance();
	_ent->GetComponent<eden_ec::CRigidBody>()->SetTemporalDeactivation(true);

	timerPos = timeToChange;
	timerEvent = timeToSendEvent;
}


void damn::BootMovement::Update(float deltaTime)
{

	//ManualControl();

	timerPos += deltaTime;
	timerEvent += deltaTime;

	if (timerEvent > timeToSendEvent) {
		timerEvent = 0;
		SetPositionEvent();
	}
	if (timerPos > timeToChange) {
		timerPos = 0;
		_direction = eden_utils::Vector3(0, 0, 0);
		int dir;
		for (int i = 0; i < 4; i++) {
			dir= rand() % 4;
			switch (dir)
			{
				case 0:	_direction += _transform->GetForward() * -1;break;
				case 1:	_direction += _transform->GetForward();break;
				case 2:	_direction += _transform->GetRight();break;
				case 3:	_direction += _transform->GetRight() * -1;break;
				default:break;
			}
		}
		_direction = _direction.Normalized();
	}

	

	if (_inputManager->IsKeyDown(eden_input::InputManager::ESCAPE)) {
		eden::SceneManager::getInstance()->FindEntity("GAME_MANAGER")->GetComponent<GameManager>()->Pause(true);
		eden::SceneManager::getInstance()->PushScene("PauseMenu");
	}

	if (_rigidBody) {
		eden_utils::Vector3 vel = _rigidBody->GetLinearVelocity();
		vel = eden_utils::Vector3(_direction.GetX() * _speed, vel.GetY(), _direction.GetZ() * _speed);
		_rigidBody->SetLinealVelocity(vel);
	}
}

void damn::BootMovement::ManualControl()
{
	_direction = eden_utils::Vector3(0, 0, 0);
	std::pair<int, int> aux;
	if (_inputManager->IsKeyHeld('w')) {
		_direction += _transform->GetForward() * -1;
	}
	else if (_inputManager->IsKeyHeld('s')) {
		_direction += _transform->GetForward();
	}
	if (_inputManager->IsKeyDown('d')) {
		_direction += _transform->GetRight();
	}
	else if (_inputManager->IsKeyHeld('a')) {
		_direction += _transform->GetRight() * -1;
	}
	
	_direction = _direction.Normalized();

	if (_cameraMovement)
		_cameraMovement->SetMouseDirection(eden_input::InputManager::getInstance()->GetMouseDir());
}

void damn::BootMovement::SetPositionEvent()
{
	PositionEvent* _pos = new PositionEvent(false, _transform->GetPosition().GetX(), _transform->GetPosition().GetY(), _transform->GetPosition().GetZ());
	if (Tracker::Instance()) {
		Tracker::Instance()->TrackEvent(_pos);

	}
	else delete _pos;
}