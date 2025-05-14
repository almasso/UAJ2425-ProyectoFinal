--Definicion de la clase en Lua
botCollision = {}

botCollision.__index = botCollision

--Constructor de la clase en Lua
function botCollision:new()
	local obj={}
	setmetatable(obj, botCollision)
	return obj
end

--Metodo OnCollisionEnter
function botCollision:OnCollisionEnter()
	BotCollision:HasBotCollided();
end
function botCollision:OnCollisionStay()
	--BotCollision:HasBotCollided();
end
function botCollision:OnCollisionExit()
	BotCollision:CollisionExit();
end
--Variable global de la clase (para Luabridge)
botCollisionLua = botCollision:new()