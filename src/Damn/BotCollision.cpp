#include "BotCollision.h"
#include <ComponentArguments.h>
#include <iostream>

void damn::BotCollision::Init(eden_script::ComponentArguments* args)
{
	Bot::Init(args);
	_anglesToRotate = args->GetValueToInt("AnglesToRotate");
}

void damn::BotCollision::Update(float deltaTime)
{
	if (_coll) {
		float angle = rand() % (2 * _anglesToRotate);
		_transform->Yaw(angle - _anglesToRotate);
		_coll = false;
	}

	Bot::Update(deltaTime);
}

void damn::BotCollision::ChangeDirection()
{
	_coll = true;
}

void damn::BotCollision::Start()
{
	_coll = false;
	Bot::Start();
}

void damn::BotCollision::BotMove()
{
	_direction = eden_utils::Vector3(0, 0, 0);
	_direction += _transform->GetForward() * -1;
	_direction = _direction.Normalized();
}

