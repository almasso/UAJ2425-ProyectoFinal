#include "Entity.h"
#include "Bot.h"
#include <ComponentArguments.h>
#include "CameraMovement.h"
#include "PositionEvent.h"
#include "Tracker.h"
#include<InputManager.h>
#include "SceneManager.h"
#include "GameManager.h"

void damn::Bot::Update(float deltaTime)
{
    timerEvent += deltaTime;
    if (timerEvent > timeToSendEvent) {
        timerEvent = 0;
        SetPositionEvent();
    }

    BotMove();

    if (_rigidBody) {
        eden_utils::Vector3 vel = _rigidBody->GetLinearVelocity();
        vel = eden_utils::Vector3(_direction.GetX() * _speed, vel.GetY(), _direction.GetZ() * _speed);
        _rigidBody->SetLinealVelocity(vel);
    }

    if (_inputManager->IsKeyDown(eden_input::InputManager::ESCAPE)) {
        eden::SceneManager::getInstance()->FindEntity("GAME_MANAGER")->GetComponent<GameManager>()->Pause(true);
        eden::SceneManager::getInstance()->PushScene("PauseMenu");
    }
}

void damn::Bot::Init(eden_script::ComponentArguments* args)
{
    _speed = args->GetValueToFloat("Speed");
    timeToSendEvent = args->GetValueToFloat("SendEventTime");
    stuckRange = args->GetValueToFloat("StuckRange");
    numLastPositions = args->GetValueToInt("NumCheckPositions");
}

void damn::Bot::Start()
{
    _rigidBody = _ent->GetComponent<eden_ec::CRigidBody>();
    _transform = _ent->GetComponent<eden_ec::CTransform>();
    _cameraMovement = _ent->GetComponent<damn::CameraMovement>();
    _inputManager = eden_input::InputManager::getInstance();
    _iniPos = _transform->GetPosition();
    _iniRot = _transform->GetRotation();
    timerEvent = 0;
    lastPositions = std::deque<eden_utils::Vector3>();
    isStuck = false;
    _rigidBody->SetTemporalDeactivation(true);
}

float damn::Bot::distanceSquared(eden_utils::Vector3 a, eden_utils::Vector3 b)
{
    float dx = a.GetX() - b.GetX();
    float dy = a.GetY() - b.GetY();
    float dz = a.GetZ() - b.GetZ();

    return dx * dx + dy * dy + dz * dz;
}

bool damn::Bot::IsStuck()
{
    float thresholdSq = stuckRange * stuckRange;
    float maxDis = 0.0f;

    for (int i = 0; i < lastPositions.size(); i++) {
        for (int j = i + 1; j < lastPositions.size(); j++)
        {
            float distSqrt = distanceSquared(lastPositions[i], lastPositions[j]);
            if (distSqrt > maxDis) {
                maxDis = distSqrt;
            }
        }
    }
    return maxDis < thresholdSq;
}

void damn::Bot::SetPositionEvent()
{
    isStuck = false;
    lastPositions.push_back(_transform->GetPosition());
    if (lastPositions.size() == numLastPositions) {
        isStuck = IsStuck();
        lastPositions.pop_front();
    }

    PositionEvent* _pos = new PositionEvent(isStuck, _transform->GetPosition().GetX(), _transform->GetPosition().GetY(), _transform->GetPosition().GetZ());
    if (Tracker::Instance()) {
        Tracker::Instance()->TrackEvent(_pos);
    }
    else delete _pos;
    
    if (isStuck) {
        _transform->SetPosition(_iniPos);
        _transform->SetRotation(_iniRot);
        lastPositions.clear();
        _direction = eden_utils::Vector3(0, 0, 0);
    }
}
