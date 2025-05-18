#pragma once

#include <Component.h>
#include <Vector3.h>
#include <vector>
#include <unordered_map>
#include "EDENcm/EDENcmStatements.h"
#include <Entity.h>
#include <functional>

namespace std {
	template <>
	struct hash<eden_utils::Vector3> {
		size_t operator()(const eden_utils::Vector3& vec) const {
			// Combine los valores de x, y y z en un hash único
			return ((std::hash<float>()(vec.GetX())
				^ (std::hash<float>()(vec.GetY()) << 1)) >> 1)
				^ (std::hash<float>()(vec.GetZ()) << 1);
		}
	};
}

namespace damn {
	class HeatMapDrawer : public eden_ec::Component
	{
	public:
		HeatMapDrawer();
		
		static std::string GetID() { return "HEAT_MAP_DRAWER"; }

		void DiscretizeReadData(float gridSize);

		void ReadData(std::string fileName);

		void InstantiateHeatMapData(bool showStuck, float minSphereSize);
	protected:
		void Init(eden_script::ComponentArguments* args) override {};

		void Awake() override {};

		void Start() override {};


		eden_ec::Entity* InstanceHeatSphere(float scaleFactor, const eden_utils::Vector3& spawnPosition);
		/// @brief Variable que comprueba que si ya se ha mostrado el mapa no se pueda mostrar de nuevo
		bool _alreadyShownPoints = false;
		/// @brief Tamaño de cada celda
		float _gridSize = 10.f;
		/// @brief Valor usado para calcular el tamaño de cada esfera mediante proporciones
		float _maxGridValue = 1;
		/// @brief Vector que guarda las posiciones registradas directamente
		std::vector<eden_utils::Vector3> heatPositions;
		/// @brief Vector que guarda las posiciones de atascos registradas directamente
		std::vector<eden_utils::Vector3> stuckPositions;
		/// @brief Vector que guarda las posiciones registradas de manera discretizada según el tamaño de las celdas
		std::unordered_map<eden_utils::Vector3, int> parsedGridPositions;
	};
}


