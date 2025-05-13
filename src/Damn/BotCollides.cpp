#include <ScriptManager.h>
#include <LuaManager.h>
#include <Entity.h>

#include "CRigidBody.h"

#include "BotCollides.h"
#include "BotCollision.h"

void damn::BotCollides::Start()
{
	eden_script::LuaManager* _luaMngr = eden_script::ScriptManager::getInstance()->GetLuaManager();
	_luaMngr->Regist(*this, "BotCollision", &damn::BotCollides::HasBotCollided, "HasBotCollided", this);
	_luaMngr->SetGlobal(*this, "BotCollision");
	_luaMngr = nullptr;
}

void damn::BotCollides::HasBotCollided()
{
	eden_ec::Entity* _other = luabridge::getGlobal(eden_script::ScriptManager::getInstance()->GetLuaManager()->GetLuaState(), "other");
	eden_ec::Entity* _self = luabridge::getGlobal(eden_script::ScriptManager::getInstance()->GetLuaManager()->GetLuaState(), "self");

	if (_other->GetComponent<eden_ec::CRigidBody>()->GetCollisionLayerName() != "FLOOR") {
		_self->GetComponent<BotCollision>()->ChangeDirection();
	}
}
