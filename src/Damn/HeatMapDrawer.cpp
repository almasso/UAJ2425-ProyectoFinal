#include "HeatMapDrawer.h"
#include "SceneManager.h"
#include <iostream>
#include <CMeshRenderer.h>
#include <Transform.h>
#include <ComponentArguments.h>

damn::HeatMapDrawer::HeatMapDrawer()
{
}

void damn::HeatMapDrawer::ShowHeatMapData()
{
    //comprobación para que no se pueda volver a mostrar los puntos si ya se han mostrado
    if (_alreadyShownPoints) return;
    _alreadyShownPoints = true;
    eden_utils::Vector3 spawnPosition;
    for (auto cell : parsedGridPositions) {
        spawnPosition = cell.first;
        spawnPosition *= _gridSize;
        float scaleFactor = cell.second / _maxGridValue;
        eden_ec::Entity* e = InstanceHeatSphere(scaleFactor, spawnPosition);
        eden_utils::Vector3 scale(scaleFactor, scaleFactor, scaleFactor);
        std::cout << "Nueva escala: " << scale.GetX() << " " << scale.GetY() << " " << scale.GetZ() << "  Count " << cell.second << "  max: " << _maxGridValue << std::endl;
        e->GetComponent<eden_ec::CTransform>()->SetScale(scale);
        //e->GetComponent<eden_ec::CMeshRenderer>()->SetMaterial("Wall");
    }
}

void damn::HeatMapDrawer::ParseReadData()
{
    if (readPositions.empty()) return;
    for (auto position : readPositions) {
        eden_utils::Vector3 equivalentGrid = position / _gridSize;
        equivalentGrid = { ceil(equivalentGrid.GetX()), ceil(equivalentGrid.GetY()), ceil(equivalentGrid.GetZ()) };
        auto it = parsedGridPositions.find(equivalentGrid);
        if (it != parsedGridPositions.end()) {
            it->second++;
            _maxGridValue = std::max((float)it->second, _maxGridValue);
        }
        else {
            parsedGridPositions.insert({ equivalentGrid, 1 });
        }
    }
}

eden_ec::Entity* damn::HeatMapDrawer::InstanceHeatSphere(float scaleFactor, const eden_utils::Vector3& spawnPosition)
{
    eden_ec::Entity* spawnedEntity = nullptr;
    if (scaleFactor <= 0.2) {
        spawnedEntity = eden::SceneManager::getInstance()->InstantiateBlueprint("YellowSphere", spawnPosition);
    }
    else if (scaleFactor <= 0.4) {
        spawnedEntity = eden::SceneManager::getInstance()->InstantiateBlueprint("YellowMidSphere", spawnPosition);
    }
    else if (scaleFactor <= 0.6) {
        spawnedEntity = eden::SceneManager::getInstance()->InstantiateBlueprint("OrangeSphere", spawnPosition);
    }
    else if (scaleFactor <= 0.8) {
        spawnedEntity = eden::SceneManager::getInstance()->InstantiateBlueprint("OrangeMidSphere", spawnPosition);
    }
    else{
        spawnedEntity = eden::SceneManager::getInstance()->InstantiateBlueprint("RedSphere", spawnPosition);
    }
    return spawnedEntity;
}


void damn::HeatMapDrawer::Init(eden_script::ComponentArguments* args)
{
	_gridSize = args->GetValueToFloat("GridSize");
	std::string dataFile = args->GetValueToString("File");
	//TODO leer valores y guardarlos en una estructura de datos
	
}

void damn::HeatMapDrawer::Start()
{
    //Esto es para pruebas
    /*readPositions = {{12, -23, 34}, {45, -11, -9}, {-30, 5, 48}, {17, 0, -25}, {3, -46, 22},
    {-50, 13, 29}, {27, -18, -36}, {-12, 9, 41}, {6, 33, -10}, {-38, -45, 0},
    {44, 8, -27}, {15, 19, -1}, {-5, -5, -5}, {0, 0, 0}, {-7, 50, -20},
    {31, -7, 12}, {22, 14, -15}, {-2, -14, 39}, {25, -50, 24}, {9, 18, -33},
    {-29, 20, 7}, {1, -1, 1}, {37, 26, -19}, {10, -30, 44}, {48, -48, 48},
    {-26, 38, -12}, {0, 15, -16}, {5, -39, 2}, {-43, 7, -30}, {39, 0, -5},
    {-8, 50, 50}, {-31, -11, 3}, {20, 21, -13}, {4, -6, -50}, {-24, -20, 20},
    {16, 35, 18}, {-49, 49, -49}, {13, -3, -22}, {-10, 36, 40}, {30, -2, 11},
    {-15, 6, 6}, {11, -35, -44}, {7, 7, 7}, {-34, 1, -41}, {-21, -8, 9},
    {8, 17, 0}, {-6, 12, -17}, {2, -29, 32}, {-33, 27, -38}, {19, -21, 23} };*/

    //Esto es para probar en plano
    readPositions = { {12, 10, 34}, {45, 10, -9}, {-30, 10, 48}, {17, 10, -25}, {3, 10, 22},
 {-50, 10, 29}, {27, 10, -36}, {-12, 10, 41}, {6, 10, -10}, {-38, 10, 0},
 {44, 10, -27}, {15, 10, -1}, {-5, 10, -5}, {0, 10, 0}, {-7, 10, -20},
 {31, 10, 12}, {22, 10, -15}, {-2, 10, 39}, {25, 10, 24}, {9, 10, -33},
 {-29, 10, 7}, {1, 10, 1}, {37, 10, -19}, {10, 10, 44}, {48, 10, 48},
 {-26, 10, -12}, {0, 10, -16}, {5, 10, 2}, {-43, 10, -30}, {39, 10, -5},
 {-8, 10, 50}, {-31, 10, 3}, {20, 10, -13}, {4, 10, -50}, {-24, 10, 20},
 {16, 10, 18}, {-49, 10, -49}, {13, 10, -22}, {-10, 10, 40}, {30, 10, 11},
 {-15, 10, 6}, {11, 10, -44}, {7, 10, 7}, {-34, 10, -41}, {-21, 10, 9},
 {8, 10, 0}, {-6, 10, -17}, {2, 10, 32}, {-33, 10, -38}, {19, 10, 23} };
    ParseReadData();
    ShowHeatMapData();
}
