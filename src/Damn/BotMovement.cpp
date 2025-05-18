#include "BotMovement.h"
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


void damn::BotMovement::Init(eden_script::ComponentArguments* args)
{
	Bot::Init(args);
	timeToChange = args->GetValueToFloat("ChangeDirectionTime");
}

void damn::BotMovement::Start()
{
	Bot::Start();

	timerPos = 0;
}


void damn::BotMovement::Update(float deltaTime)
{
	//ManualControl();
	timerPos += deltaTime;	

	Bot::Update(deltaTime);
	
}


void damn::BotMovement::BotMove()
{
	if (isStuck) {
		timerPos = 0;
		isStuck = false;
	}
	else if (timerPos > timeToChange) {
		timerPos = 0;
		_direction = eden_utils::Vector3(0, 0, 0);
		int dir;
		for (int i = 0; i < 5; i++) {
			dir = rand() % 4;
			switch (dir)
			{
			case 0:	_direction += _transform->GetForward() * -1; break;
			case 1:	_direction += _transform->GetForward(); break;
			case 2:	_direction += _transform->GetRight(); break;
			case 3:	_direction += _transform->GetRight() * -1; break;
			default:break;
			}
		}
		_direction = _direction.Normalized();
	}
}

void damn::BotMovement::ManualControl()
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