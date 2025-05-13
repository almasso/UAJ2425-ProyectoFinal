#ifndef _BOT_H
#define _BOT_H

#include <Component.h>
#include <Vector3.h>
#include <CRigidBody.h>
#include <deque>

namespace eden_input {
	class InputManager;
}

namespace damn {
	class Bot : public eden_ec::Component
	{
	public:
		/// @brief Constructora por defecto
		Bot() = default;

		/// @brief Destructora por defecto
		~Bot() override = default;

		/// @brief Metodo update heredado de Component 
		/// @param deltaTime El tiempo entre frames calculado por el motor
		void Update(float deltaTime) override;

		/// @brief ID del componente
		/// @return Devuelve el ID del componente
		static std::string GetID() { return "BOT"; }
	protected:
		/// @brief Construye el componente dado unos argumentos. Se obtendran de una lectura de un .lua
		/// @param args Argumentos leidos de .lua
		void Init(eden_script::ComponentArguments* args) override;

		/// @brief Metodo Awake override de Component
		void Awake() override {};

		/// @brief Metodo heredado de Component que se usa para coger referencias a otros componentes
		void Start() override;

		/// @brief Direccion de movimiento
		eden_utils::Vector3 _direction;
		eden_utils::Vector3 _iniPos;

		float stuckRange = 5.f;
		std::deque<eden_utils::Vector3> lastPositions;
		int numLastPositions = 120;


		/// @brief Referencia al RigidBody
		eden_ec::CRigidBody* _rigidBody = nullptr;
		/// @brief Referencia al Transform del jugador
		eden_ec::CTransform* _transform = nullptr;
		/// @brief Referencia al componente para mover la camara
		class CameraMovement* _cameraMovement = nullptr;
		// @brief Referencia al InputManager
		eden_input::InputManager* _inputManager = nullptr;

		/// @brief Velocidad de movimiento
		float _speed = 0.0f;
		float timerEvent;
		float timeToSendEvent = 0.5f;

		float distanceSquared(eden_utils::Vector3 a, eden_utils::Vector3 b);
		bool IsStuck();
		virtual void BotMove() = 0;
		void SetPositionEvent();
	};
}
#endif