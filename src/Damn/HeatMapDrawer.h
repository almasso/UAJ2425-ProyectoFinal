#pragma once

#include <Component.h>
#include <Vector3.h>
#include <vector>
#include <unordered_map>
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

		void ShowHeatMapData();

		static std::string GetID() { return "HEAT_MAP_DRAWER"; }
	protected:
		void Init(eden_script::ComponentArguments* args) override;

		void Awake() override {};

		void Start() override;

		void ParseReadData();
		eden_ec::Entity* InstanceHeatSphere(float scaleFactor, const eden_utils::Vector3& spawnPosition);

		bool _alreadyShownPoints = false;
		float _gridSize = 10.f;
		float _maxGridValue = 1;
		std::vector<eden_utils::Vector3> readPositions;
		std::unordered_map<eden_utils::Vector3, int> parsedGridPositions;
	};
}


