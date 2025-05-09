#ifndef EDEN_CANVAS_H
#define EDEN_CANVAS_H

#include <unordered_set>
#include <unordered_map>
#include <string>

#include "Singleton.h"

namespace eden_ec {
	class UIComponent;
}
namespace eden_canvas {
	class Canvas :public Singleton<Canvas>
	{
	public:
		friend Singleton<Canvas>;

		/// @brief Actualiza el tamanio y posicion de los componentes
		void Resize();

		/// @brief Inicializa los valores base de los componentes
		void InitCanvas();

		/// @brief Destructora
		~Canvas() = default;

		/// @brief Aniade un puntero a un componente de UI
		/// para actualizar su posicion y tamanio
		/// @param ent Entidad cuya posicion va a actualizarse
		void addRenderEntity(eden_ec::UIComponent* ent);

		/// @brief Quita el componente para dejar de actualizar su posicion
		/// @param ent Entidad que se va a quitar
		void removeRenderEntity(eden_ec::UIComponent* ent);

		void addScene(std::string sceneID);

		void removeScene(std::string sceneID);

		void ShowScene(std::string sceneID);

		void HideScene(std::string sceneID);
	private:
		/// @brief Constructora
		Canvas() = default;

		std::unordered_map<std::string, std::unordered_set<eden_ec::UIComponent*>> _entities;
	};
}
#endif //__CANVAS_H__
