#ifndef _BOT_COLLIDES_H
#define _BOT_COLLIDES_H

#include "Component.h"

namespace damn {
	class BotCollides : public eden_ec::Component
	{
	public:
		/// @brief Constructora por defecto del componente
		BotCollides() = default;
		/// @brief Constructora por defecto del componente
		~BotCollides() override = default;
		/// @brief ID del componente
		/// @return Devuelve el ID del componente
		static std::string GetID() { return "BOT_COLLIDES"; }
		
		/// @brief Callback de colisión del bot
		void HasBotCollided();
	protected:
		/// @brief Construye el componente dado unos argumentos. Se obtendran de una lectura de un .lua
		/// @param args Argumentos leidos de .lua
		void Init(eden_script::ComponentArguments* args) override {};

		/// @brief Metodo Awake override de Component
		void Awake() override {};

		/// @brief Metodo heredado de Component que se usa para coger referencias a otros componentes
		void Start() override;
	};
}

#endif