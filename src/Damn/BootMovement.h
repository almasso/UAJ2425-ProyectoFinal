
#ifndef _BOOT_MOVEMENT_H
#define _BOOT_MOVEMENT_H

#include <Component.h>
#include <Vector3.h>
#include <Transform.h>
#include <CRigidBody.h>


namespace eden_input {
	class InputManager;
}

namespace damn {
	class BootMovement : public eden_ec::Component
	{
	public:
		/// @brief Constructora por defecto
		BootMovement() = default;

		/// @brief Destructora por defecto
		~BootMovement() override = default;

		/// @brief Metodo update heredado de Component 
		/// @param deltaTime El tiempo entre frames calculado por el motor
		void Update(float deltaTime) override;

		/// @brief ID del componente
		/// @return Devuelve el ID del componente
		static std::string GetID() { return "BOOT_MOVEMENT"; }

	protected:

		/// @brief Construye el componente dado unos argumentos. Se obtendran de una lectura de un .lua
		/// @param args Argumentos leidos de .lua
		void Init(eden_script::ComponentArguments* args) override;

		/// @brief Metodo Awake override de Component
		void Awake() override {};

		/// @brief Metodo heredado de Component que se usa para coger referencias a otros componentes
		void Start() override;

	private:
		/// @brief Direccion de movimiento
		eden_utils::Vector3 _direction;

		/// @brief Velocidad de movimiento
		float _speed = 0.0f;

		/// @brief Referencia al RigidBody
		eden_ec::CRigidBody* _rigidBody = nullptr;

		//TEMP//////////////////////////////////////////////////////////////////////////
		// @brief Referencia al InputManager
		eden_input::InputManager* _inputManager = nullptr;
		/// @brief Referencia al Transform del jugador
		eden_ec::CTransform* _transform = nullptr;
		/// @brief Referencia al componente para mover la camara
		class CameraMovement* _cameraMovement = nullptr;

		float timerPos = 0;
		float timerEvent = 0;
		float timeToChange = 3;
		float timeToSendEvent = 1.f;

		void SetPositionEvent();
		void ManualControl();
		//TEMP//////////////////////////////////////////////////////////////////////////
	};
}


#endif