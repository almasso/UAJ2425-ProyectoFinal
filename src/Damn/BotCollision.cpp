#include "BotCollision.h"
#include <ComponentArguments.h>

void damn::BotCollision::Init(eden_script::ComponentArguments* args)
{
	Bot::Init(args);
	_anglesToRotate = args->GetValueToFloat("AnglesToRotate");
}

void damn::BotCollision::Update(float deltaTime)
{
	Bot::Update(deltaTime);
}

void damn::BotCollision::ChangeDirection()
{
	_transform->Yaw(_anglesToRotate);
}

void damn::BotCollision::Start()
{
	Bot::Start();
}

void damn::BotCollision::BotMove()
{
	_direction = eden_utils::Vector3(0, 0, 0);
	_direction += _transform->GetForward();
	_direction = _direction.Normalized();
}

