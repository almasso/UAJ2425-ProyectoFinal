#include <iostream>

#pragma warning(push)
#pragma warning(disable : 26495)
#pragma warning(disable : 4251)
#include <OgreSceneNode.h>
#include <OgreRoot.h>
#include <OgreVector.h>
#pragma warning(pop)

#include "NodeManager.h"
#include "Vector3.h"
#include "Quaternion.h"
#include "RenderManager.h"
#include "RenderObject.h"
#include "ErrorHandler.h"

render_wrapper::NodeManager::NodeManager() {
	//Inicializamos el unordered_map de nodos e ID de entidades 
	_sceneObjectsMap = std::unordered_map<std::string, std::unordered_map<std::string, Ogre::SceneNode*>>();

	//Hacemos referencia al nodo raiz de Ogre mediante el RenderManager
	Ogre::SceneManager* mSM = eden_render::RenderManager::Instance()->_currentRenderScene->_renderScene;
	_rootNode = mSM->getRootSceneNode();
}

render_wrapper::NodeManager::~NodeManager() {
	// Borramos todo lo que haya en el unordered_map
	// El metodo clear() llama a las destructoras de los objetos que contiene, por lo que esta parte deberia estar libre de memory leaks
	_sceneObjectsMap.clear();
}

eden_utils::Vector3 render_wrapper::NodeManager::ConvertToEdenVector(const Ogre::Vector3 ogreVector) {
	eden_utils::Vector3 edenVector = eden_utils::Vector3(ogreVector.x, ogreVector.y, ogreVector.z);
	return edenVector;
}
Ogre::Vector3 render_wrapper::NodeManager::ConvertToOgreVector(const eden_utils::Vector3 edenVector) {
	Ogre::Vector3 ogreVector = Ogre::Vector3(edenVector.GetX(), edenVector.GetY(), edenVector.GetZ());
	return ogreVector;
}

eden_utils::Quaternion render_wrapper::NodeManager::ConvertToEdenQuaternion(const Ogre::Quaternion ogreVector) {
	eden_utils::Quaternion edenQuaternion = eden_utils::Quaternion(ogreVector.w, ogreVector.x, ogreVector.y, ogreVector.z);
	return edenQuaternion;
}

Ogre::Quaternion render_wrapper::NodeManager::ConvertToOgreQuaternion(const eden_utils::Quaternion edenQuaternion) {
	Ogre::Quaternion ogreQuaternion = Ogre::Quaternion(edenQuaternion.Real(), edenQuaternion.Complex().GetX(),
		edenQuaternion.Complex().GetY(), edenQuaternion.Complex().GetZ());
	return ogreQuaternion;
}

bool render_wrapper::NodeManager::HasNode(const std::string id, const std::string sceneID) {
	return FindNode(id, sceneID, false) != nullptr;
}

Ogre::SceneNode* render_wrapper::NodeManager::FindNode(const std::string id, const std::string sceneID, bool showWarnings) {
	auto aux = _sceneObjectsMap.find(sceneID);
	if (aux == _sceneObjectsMap.end()) {
		if (showWarnings) {
			std::string message = "NodeManager ERROR in line 60 could not find scene: " + sceneID + "\n";

			eden_error::ErrorHandler::Instance()->Warning(message.c_str());
		}

		return nullptr;
	}

	auto auxNode = aux->second.find(id);
	if (auxNode == aux->second.end()) {
		
		if(showWarnings) eden_error::ErrorHandler::Instance()->Warning("WARNING: scene node with id: " + id + " not found in  the scene objects map\n");

		// TRATAMIENTO DE ERRORES DE LUA AQUI --------
		// Se devuelve nullptr para que el wrapper que necesite el nodo sepa que no existe 
		// y por tanto debera crear uno propio y lo asocie a la entidad
		return nullptr;
	}
	return auxNode->second;
}

void render_wrapper::NodeManager::CreateSceneObject(const std::string id, const std::string sceneID) {
	Ogre::SceneManager* mSM = eden_render::RenderManager::Instance()->_renderScenes[sceneID]->GetRenderScene();
	_rootNode = mSM->getRootSceneNode();
	std::string nodeID = id + "_" + sceneID;
	Ogre::SceneNode* auxNode = _rootNode->createChildSceneNode(nodeID);
	_sceneObjectsMap[sceneID].insert({ id, auxNode });
}

void render_wrapper::NodeManager::AddChildToObject(const std::string idChild, const std::string idParent, const std::string sceneID) {
	std::string parentNodeID = idParent + "_" + sceneID;
	Ogre::SceneNode* parent = FindNode(idParent, sceneID);
	std::string childNodeID = idChild + "_" + sceneID;
	Ogre::SceneNode* auxNode = parent->createChildSceneNode(childNodeID);
	_sceneObjectsMap[sceneID].insert({ idChild, auxNode });
}

eden_utils::Vector3 render_wrapper::NodeManager::GetPosition(const std::string id, const std::string sceneID) {
	Ogre::Vector3 ogreVector = FindNode(id, sceneID)->getPosition();
	return ConvertToEdenVector(ogreVector);
}

eden_utils::Vector3 render_wrapper::NodeManager::GetScale(const std::string id, const std::string sceneID) {
	Ogre::Vector3 ogreVector = FindNode(id, sceneID)->getScale();
	return ConvertToEdenVector(ogreVector);
}

void render_wrapper::NodeManager::RemoveSceneObject(const std::string id, const std::string sceneID) {
	auto aux = _sceneObjectsMap.find(sceneID);
	if (aux == _sceneObjectsMap.end()) {
		eden_error::ErrorHandler::Instance()->Warning("scene node with id : " + id + " not found in  the scene objects map\n");
	}
	else {
		auto auxNode = aux->second.find(id);
		if (auxNode != aux->second.end()) {
			auxNode->second->removeAndDestroyAllChildren();
			eden_render::RenderManager::Instance()->_renderScenes[sceneID]->GetRenderScene()->destroySceneNode(auxNode->second);
			_sceneObjectsMap.erase(aux);
		}
	}
}

void render_wrapper::NodeManager::RemoveScene(const std::string sceneID) {
	auto aux = _sceneObjectsMap.find(sceneID);
	if (aux != _sceneObjectsMap.end()) {
		_sceneObjectsMap.erase(aux);
	}
}

void render_wrapper::NodeManager::Attach(Ogre::MovableObject* obj, const std::string id, const std::string sceneID) {
	FindNode(id, sceneID)->attachObject(obj);
}

void render_wrapper::NodeManager::SetPosition(const eden_utils::Vector3 pos, const std::string id, const std::string sceneID) {
	FindNode(id, sceneID)->setPosition(ConvertToOgreVector(pos));
}

void render_wrapper::NodeManager::SetOrientation(const eden_utils::Quaternion quat, const std::string id, const std::string sceneID) {
	FindNode(id, sceneID)->setOrientation(ConvertToOgreQuaternion(quat));
}

void render_wrapper::NodeManager::ShowBoundingBox(bool active, const std::string id, const std::string sceneID) {
	FindNode(id, sceneID)->showBoundingBox(active);
}

void render_wrapper::NodeManager::Rotate(const eden_utils::Vector3 rotation, const std::string id, const std::string sceneID) {
	Ogre::SceneNode* aux = FindNode(id, sceneID);
	aux->pitch(Ogre::Degree(rotation.GetX()));
	aux->yaw(Ogre::Degree(rotation.GetY()));
	aux->roll(Ogre::Degree(rotation.GetZ()));

}

void render_wrapper::NodeManager::RotateLocal(const eden_utils::Vector3 rotation, const std::string id, const std::string sceneID) {
	Ogre::SceneNode* aux = FindNode(id, sceneID);
	aux->pitch(Ogre::Degree(rotation.GetX()), Ogre::Node::TS_LOCAL);
	aux->yaw(Ogre::Degree(rotation.GetY()), Ogre::Node::TS_LOCAL);
	aux->roll(Ogre::Degree(rotation.GetZ()), Ogre::Node::TS_LOCAL);
}

void render_wrapper::NodeManager::Scale(const eden_utils::Vector3 scale, const std::string id, const std::string sceneID) {
	FindNode(id, sceneID)->setScale(ConvertToOgreVector(scale));
}

void render_wrapper::NodeManager::Translate(const eden_utils::Vector3 pos, const std::string id, const std::string sceneID) {
	FindNode(id, sceneID)->translate(ConvertToOgreVector(pos), Ogre::Node::TS_LOCAL);
}

void render_wrapper::NodeManager::LookAt(const eden_utils::Vector3 pos, const std::string id, const std::string sceneID) {
	FindNode(id, sceneID)->lookAt(ConvertToOgreVector(pos), Ogre::Node::TS_WORLD);
}
