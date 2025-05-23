#ifndef EDEN_INPUT_MANAGER_H
#define EDEN_INPUT_MANAGER_H

#include <array>
#include <unordered_map>

#include "Singleton.h"

#include "defs.h"

class InputWrapper;
namespace eden_input 
{
	/// @brief Clase que gestiona la entrada de datos del usuario.
	class InputManager : public Singleton<InputManager>
	{
		friend Singleton<InputManager>;
	public:

		/// @brief enumerado de los botones del raton
		enum MOUSEBUTTON : uint8_t { LEFT = 0, MIDDLE = 1, RIGHT = 2 };

		/// @brief enumerado de las teclas especiales
		enum SPECIALKEY : uint8_t {
			RETURN = 40,
			ESCAPE = 41,
			BACKSPACE = 42,
			TAB = 43,
			SPACE = 44,
			MINUS = 45,
			EQUALS = 46,
			LEFTBRACKET = 47,
			RIGHTBRACKET = 48,
			BACKSLASH = 49,
			NONUSHASH = 50,
			SEMICOLON = 51,
			APOSTROPHE = 52,
			GRAVE = 53,
			COMMA = 54,
			PERIOD = 55,
			SLASH = 56,
			CAPSLOCK = 57,
			F1 = 58,
			F2 = 59,
			F3 = 60,
			F4 = 61,
			F5 = 62,
			F6 = 63,
			F7 = 64,
			F8 = 65,
			F9 = 66,
			F10 = 67,
			F11 = 68,
			F12 = 69,
			
			PRINTSCREEN = 70,
			SCROLLLOCK = 71,
			
			PAUSE = 72,
			INSERT = 73,
			HOME = 74,
			
			PAGEUP = 75,
			SUPR = 76,
			END = 77,
			PAGEDOWN = 78,
			
			ARROW_RIGHT = 79,
			ARROW_LEFT = 80,
			ARROW_DOWN = 81,
			ARROW_UP = 82,

			NUMLOCKCLEAR = 83,
			KP_DIVIDE = 84,
			KP_MULTIPLY = 85,
			KP_MINUS = 86,
			KP_PLUS = 87,

			LCTRL = 224,
			LSHIFT = 225,
			LALT = 226,
			RCTRL = 228,
			RSHIFT = 229,
			RALT = 230
		};

		/// @brief Limpieza del mapa de teclas
		EDEN_API void Clean();

		/// @brief True si se esta pulsando
		/// al menos una tecla del teclado
		EDEN_API bool KeyDownEvent();

		/// @brief True si se ha soltado
		/// al menos una tecla del teclado
		EDEN_API bool KeyUpEvent();

		/// @brief True en el primer frame
		/// en el que la tecla es pulsada
		/// @param key Tecla Normal (0-9 y a-z)
		EDEN_API bool IsKeyDown(char key);

		/// @brief True mientras
		/// la tecla esta pulsada
		/// @param key Tecla Normal (0-9 y a-z)
		EDEN_API bool IsKeyHeld(char key);

		/// @brief True en el primer frame
		/// en el que la tecla es liberada
		/// @param key Tecla Normal (0-9 y a-z)
		EDEN_API bool IsKeyUp(char key);

		/// @brief True en el primer frame
		/// en el que la tecla es pulsada
		/// @param key Tecla Especial (macros SPECIALKEY)
		EDEN_API bool IsKeyDown(SPECIALKEY key);

		/// @brief True mientras
		/// la tecla esta pulsada
		/// @param key Tecla Normal (macros SPECIALKEY)
		EDEN_API bool IsKeyHeld(SPECIALKEY key);

		/// @brief True en el primer frame
		/// en el que la tecla es liberada
		/// @param key Tecla Normal (macros SPECIALKEY)
		EDEN_API bool IsKeyUp(SPECIALKEY key);

		/// @brief mouse
		/// @brief True si el raton
		/// ha cambiado de posicion
		EDEN_API bool MouseMotionEvent();

		/// @brief True si al menos un boton
		/// del raton ha cambiado de estado
		EDEN_API bool MouseButtonEvent();

		/// @brief True en el primer frame
		/// en el que el boton del raton es pulsado
		/// @param b Boton del raton (macros MOUSEBUTTON)
		EDEN_API bool IsMouseButtonDown(int b);

		/// @brief True mientras
		/// el boton del raton esto pulsado
		/// @param b Boton del raton (macros MOUSEBUTTON)
		EDEN_API bool IsMouseButtonHeld(int b);

		/// @brief True en el primer frame
		/// en el que el boton del raton es liberado
		/// @param b Boton del raton (macros MOUSEBUTTON)
		EDEN_API bool IsMouseButtonUp(int b);

		/// @brief Par (X, Y) de
		/// la posicion del raton en la pantalla.
		EDEN_API const std::pair<int, int>& GetMousePos();

		EDEN_API inline const std::pair<int, int>& GetMouseDir() { return _mouseDir; }

		//window events

		/// @brief Devuelve true cuando el usuario ha pulsado la X de la ventana
		EDEN_API bool CloseWindowEvent();

		/// @brief Se llama para cerrar la ventana de sdl (en el boto de quit del menu
		/// por ejemplo)
		EDEN_API void SetCloseWindow();

		/// @brief Devuelve true cuando el usuario ha cambiado el tamaño de la ventana
		EDEN_API bool ResizedWindowEvent();

		/// @brief Update
		EDEN_API void Update();

		/// @brief Activa o desactiva el Input segun el bool active
		EDEN_API void SetActive(bool active);

		EDEN_API inline const bool IsActive() { return _isActive; }

		/// @brief Devuelve una instancia al InputManager
		EDEN_API static InputManager* getInstance();

		/// @brief Destructora de la clase
		~InputManager() override;

	private:

		/// @brief Puntero del wrapper (SDL)
		InputWrapper* _wrapper = nullptr;

		/// @brief Booleano que indica si se el InputManager esta activo y puede recibir input del usuario
		bool _isActive = true;

		/// @brief Booleano de si se ha dejado de pulsar una tecla
		bool _isKeyUpEvent = false;

		/// @brief Booleano de si se ha pulsado una tecla
		bool _isKeyDownEvent = false;

		/// @brief Mapa de teclas y su estado
		std::unordered_map<uint8_t, uint8_t> _kbState;

		/// @brief Booleano de si se ha movido el raton
		bool _isMouseMotionEvent = false;
		
		/// @brief Booleano de si se ha pulsado algun boton del raton
		bool _isMouseButtonEvent = false;

		/// @brief Posicion del raton
		std::pair<int, int> _mousePos;

		/// @brief Dirección de movimiento del ratón
		std::pair<int, int> _mouseDir;

		/// @brief Estado del raton
		std::array<uint8_t, 3> _mbState;

		/// @brief Booleano de si se cierra la ventana
		bool _isCloseWindowEvent = false;

		/// @brief Booleano de si se cambia el tamanio la ventana
		bool _isResizedWindowEvent = false;

		/// @brief Estados de botones
		enum STATE : uint8_t {
			RELEASED = 0,
			DOWN = 1,
			HELD = 2,
			UP = 3,
		};

		/// @brief Gestiona el cambio de estados de los botones de teclado, mando y
		/// raton (DOWN -> HELD y UP -> RELEASE). Resetea las flags de los
		/// eventos
		void ClearState();

		/// @brief Actualiza el estado de las teclas del teclado
		void OnKeyDown();

		/// @brief Actualiza el estado de las teclas del teclado
		void OnKeyUp();

		/// @brief Actualiza la posici�n del rat�n
		void OnMouseMotion();

		/// @brief Actualiza el estado de los botones del raton
		void OnMouseButtonChange(STATE state);

		/// @brief Gestiona los eventos de ventana
		void HandleWindowEvent();
		
		/// @brief Constructora de la clase
		EDEN_API InputManager();
	};
}

#endif // __INPUT_MANAGER_H__