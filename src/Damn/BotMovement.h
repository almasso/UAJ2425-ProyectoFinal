
#ifndef _BOT_MOVEMENT_H
#define _BOT_MOVEMENT_H

#include "Bot.h"

namespace damn {
	class BotMovement : public Bot
	{
	public:
		/// @brief Constructora por defecto
		BotMovement() = default;

		/// @brief Destructora por defecto
		~BotMovement() override = default;

		/// @brief Metodo update heredado de Component 
		/// @param deltaTime El tiempo entre frames calculado por el motor
		void Update(float deltaTime) override;

		/// @brief ID del componente
		/// @return Devuelve el ID del componente
		static std::string GetID() { return "BOT_MOVEMENT"; }

	protected:

		/// @brief Construye el componente dado unos argumentos. Se obtendran de una lectura de un .lua
		/// @param args Argumentos leidos de .lua
		void Init(eden_script::ComponentArguments* args) override;

		/// @brief Metodo Awake override de Component
		void Awake() override {};

		/// @brief Metodo heredado de Component que se usa para coger referencias a otros componentes
		void Start() override;

	private:
		float timerPos;
		float timeToChange = 2.5f;

		void BotMove() override;
		void ManualControl();
	};
}


#endif