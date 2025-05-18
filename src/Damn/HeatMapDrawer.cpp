#include "HeatMapDrawer.h"
#include "SceneManager.h"
#include <iostream>
#include <CMeshRenderer.h>
#include <Transform.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include "CommandManager.h"
#include <ComponentArguments.h>

damn::HeatMapDrawer::HeatMapDrawer()
{
}

void damn::HeatMapDrawer::InstantiateHeatMapData(bool showStuck, float minSphereSize)
{
    //comprobación para que no se pueda volver a mostrar los puntos si ya se han mostrado
    if (_alreadyShownPoints) return;
    _alreadyShownPoints = true;
    eden_utils::Vector3 spawnPosition;
    for (auto cell : parsedGridPositions) {
        spawnPosition = cell.first;
        spawnPosition *= _gridSize;
        spawnPosition = { spawnPosition.GetX(), spawnPosition.GetY() + 1 , spawnPosition.GetZ()};
        float scaleFactor = cell.second / _maxGridValue;
        eden_ec::Entity* e = InstanceHeatSphere(scaleFactor, spawnPosition);
        scaleFactor = std::max(scaleFactor, minSphereSize);
        eden_utils::Vector3 scale(scaleFactor, scaleFactor, scaleFactor);
        e->GetComponent<eden_ec::CTransform>()->SetScale(scale);
    }
    if (showStuck) {
        for (auto pos : stuckPositions) {
            eden::SceneManager::getInstance()->InstantiateBlueprint("Stuck", pos);
        }
    }
}

void damn::HeatMapDrawer::DiscretizeReadData(float gridSize)
{
    if (_alreadyShownPoints) return;
    if (!heatPositions.empty()) {
        _gridSize = gridSize;
        for (auto position : heatPositions) {
            eden_utils::Vector3 equivalentGrid = position / _gridSize;
            equivalentGrid = { floor(equivalentGrid.GetX()), floor(equivalentGrid.GetY()), floor(equivalentGrid.GetZ()) };
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
}

void damn::HeatMapDrawer::ReadData(std::string fileName)
{
    if (_alreadyShownPoints) return;
    eden_command::CommandManager::getInstance()->logDebugMessage(fileName);
    std::ifstream f(fileName);
    nlohmann::json data = nlohmann::json::parse(f);
    eden_utils::Vector3 readPos;
    for (auto obj : data) {
        if (obj["eventType"] == "Position") {
            readPos = { obj["posX"],obj["posY"],obj["posZ"] };
            if (obj["isStuck"] == false) {
                heatPositions.push_back(readPos);
            }
            else {
                stuckPositions.push_back(readPos);
            }
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
