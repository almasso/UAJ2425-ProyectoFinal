#ifndef _BOT_COLLISION_H
#define _BOT_COLLISION_H

#include "Bot.h"

namespace damn {
	class BotCollision : public Bot
	{
	public:
		/// @brief Constructora por defecto
		BotCollision() = default;
		/// @brief Destructora por defecto
		~BotCollision() override = default;
		/// @brief Metodo update heredado de Component 
		/// @param deltaTime El tiempo entre frames calculado por el motor
		void Update(float deltaTime) override;

		void ChangeDirection();

		/// @brief ID del componente
		/// @return Devuelve el ID del componente
		static std::string GetID() { return "BOT_COLLISION"; }
	protected:
		/// @brief Construye el componente dado unos argumentos. Se obtendran de una lectura de un .lua
		/// @param args Argumentos leidos de .lua
		void Init(eden_script::ComponentArguments* args) override;

		/// @brief Metodo Awake override de Component
		void Awake() override {};

		/// @brief Metodo heredado de Component que se usa para coger referencias a otros componentes
		void Start() override;
	private:
		float _anglesToRotate;
		void BotMove() override;
	};
}
#endif