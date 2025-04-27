#include "DamnMain.h"
#include "SceneManager.h"
#include "ComponentFactory.h"
#include <RenderManager.h>

#include "ButtonFunctions.h"
#include "MovementController.h"
#include "InputController.h"
#include "ChangeCameraBackground.h"
#include "EnemyAttack.h"
#include "CameraMovement.h"
#include "ProjectileMovement.h"
#include "PlayerHealth.h"
#include "EnemyHealth.h"
#include "WeaponManager.h"
#include "Shotgun.h"
#include "AmmoBoxComponent.h"
#include "UIManager.h"
#include "GameManager.h"
#include "MainMenuCameraRotation.h"
#include "Spawnpoint.h"
#include "Rifle.h"
#include "BulletEnemyDamage.h"
#include "BulletPlayerDamage.h"
#include "MenuBullets.h"
#include "SoundController.h"
#include "RomeComponent.h"
#include "ProgressionTracker.h"
#include "GameEventTracker.h"
#include "Tracker.h"
#include "FilePersistence.h"
#include "ISerializer.h"

#include <chrono>      
#include <string>   
#include <regex>        // <<-- Añadido
#include <algorithm>    // std::remove_if

void RegisterComponents() {
	eden_ec::ComponentFactory* factory = eden_ec::ComponentFactory::getInstance();
	factory->RegisterComponent<damn::ButtonFunctions>();
	factory->RegisterComponent<damn::MovementController>();
	factory->RegisterComponent<damn::InputController>();
	factory->RegisterComponent<damn::ChangeCameraBackground>();
	factory->RegisterComponent<damn::MainMenuCameraRotation>();
	factory->RegisterComponent<damn::MenuBullets>();
	factory->RegisterComponent<damn::SoundController>();
	factory->RegisterComponent<damn::EnemyAttack>();
	factory->RegisterComponent<damn::CameraMovement>();
	factory->RegisterComponent<damn::ProjectileMovement>();
	factory->RegisterComponent<damn::EnemyHealth>();
	factory->RegisterComponent<damn::PlayerHealth>();
	factory->RegisterComponent<damn::WeaponManager>();
	factory->RegisterComponent<damn::WeaponComponent>();
	factory->RegisterComponent<damn::Shotgun>();
	factory->RegisterComponent<damn::AmmoBoxComponent>();
	factory->RegisterComponent<damn::UIManager>();
	factory->RegisterComponent<damn::GameManager>();
	factory->RegisterComponent<damn::Spawnpoint>();
	factory->RegisterComponent<damn::Rifle>();
	factory->RegisterComponent<damn::BulletEnemyDamage>();
	factory->RegisterComponent<damn::BulletPlayerDamage>();
	factory->RegisterComponent<damn::RomeComponent>();
}

void LoadScene() {
	eden::SceneManager* scnManager = eden::SceneManager::getInstance();
	// Desactiva los mensajes en consola al crear entidades 
	scnManager->SetDebugLog(false);
	eden_render::RenderManager::getInstance()->SetWindowName("DAMN");
	eden_render::RenderManager::getInstance()->SetWindowIcon("damnlogo64.bmp");
	scnManager->PushScene("Menu");

	InitValues init = Tracker::Init("Damn", Tracker::P_FILE, Tracker::S_JSON);
	if (init.couldInitialize) {
		init.serializer->init(nullptr);

		//a bin
		//static_cast<FilePersistence*> (init.persistence)->Init("telemetry");
		

		const std::string baseDir = "../analysis/data";

		const std::string sessionId = Tracker::Instance()->GetSessionID();
		std::string filename = baseDir + "/telemetry_" + sessionId;

		// inicializa la persistencia con la sesion
		bool canInitialize = static_cast<FilePersistence*>(init.persistence)->Init(filename);

		if (canInitialize) {
			ProgressionTracker* progressionTracker = new ProgressionTracker();
			Tracker::Instance()->AddTrackerAsset(progressionTracker);

			GameEventTracker* gameTracker = new GameEventTracker();
			Tracker::Instance()->AddTrackerAsset(gameTracker);

			Tracker::Instance()->Start();
		}
		else {
			Tracker::End();
		}
	}
}

void EndGame() {
	Tracker::End();
}