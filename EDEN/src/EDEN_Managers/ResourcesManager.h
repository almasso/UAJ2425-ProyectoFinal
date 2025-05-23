#ifndef EDEN_RESURCES_MANAGER_H
#define EDEN_RESOURCES_MANAGER_H

#include <string>
#include <set>
#include <vector>
#include "Singleton.h"

#include "defs.h"

#ifdef _MSC_VER
#define AUDIO_ROUTE "assets\\audio\\"
#define MESH_ROUTE "assets\\meshes\\"
#define MATERIALS_ROUTE "assets\\materials\\"
#define UI_ROUTE "assets\\textures\\"
#define FONTS_ROUTE "assets\\fonts\\"
#define DEFAULT_ROUTE  "assets\\default\\"
#define COMMANDS_ROUTE "commands\\"
#define BIN_ROUTE  ".\\"
#endif
#ifdef __APPLE__
#define AUDIO_ROUTE "assets/audio/"
#define MESH_ROUTE "assets/meshes/"
#define MATERIALS_ROUTE "assets/materials/"
#define UI_ROUTE "assets/textures/"
#define FONTS_ROUTE "assets/fonts/"
#define DEFAULT_ROUTE  "assets/default/"
#define BIN_ROUTE  "./"
#endif

namespace eden_resources {
    /// @brief Clase encargada de gestionar los recursos de UI
    class ResourcesManager : public Singleton<ResourcesManager> {
        friend Singleton<ResourcesManager>;
    public:
        /// @brief Enumerado de recursos
        enum Resources {
            Mesh,
            Materials,
            UI,
            Fonts,
            Audio,
            Commands,
            Default,
            Bin
        };
        /// @brief Constructora
        EDEN_API ResourcesManager();
        
        /// @brief Destructora
        EDEN_API ~ResourcesManager();

        /// @brief Metodo que comprueba si un archivo existe
        EDEN_API bool FileExist(std::string name, Resources res);
        
        /// @brief Devuelve el nombre de las mallas
        EDEN_API std::set<std::string> GetMeshes();

        /// @brief Devuelve el nombre de los materiales
        EDEN_API std::set<std::string> GetMaterials();

        /// @brief Devuelve el nombre de los elementos de UI
        EDEN_API std::set<std::string> GetUIElements();

        /// @brief Devuelve el nombre de los audios
        EDEN_API std::set<std::string> GetAudios();

        /// @brief UAJ: Devuelve el nombre de los ficheros de comandos
        EDEN_API std::set<std::string> GetCommands();

        /// @brief Devuelve las fuentes
        EDEN_API std::set<std::string> GetFonts();
        
        /// @brief Devuelve las rutas a las mallas
        EDEN_API std::set<std::string> GetRoutesMeshes();

        /// @brief Devuelve las rutas a los materiales
        EDEN_API std::set<std::string> GetRoutesMaterials();

        /// @brief Devuelve las rutas a los elementos de UI
        EDEN_API std::set<std::string> GetRoutesUIElements();

        /// @brief Devuelve las rutas a los audios
        EDEN_API std::set<std::string> GetRoutesAudios();

        /// @brief UAJ: Devuelve las rutas a los comandos 
        EDEN_API std::set<std::string> GetRoutesCommands();

        /// @brief Devuelve las rutas a las fuetnes
        EDEN_API std::set<std::string> GetRoutesFonts();

        /// @brief Devuelve la instancia del ResourcesManager
        EDEN_API static ResourcesManager* getInstance();

        /// @brief Metodo que guarda todos los archivos existentes de unas direcciones concretas
        EDEN_API void LoadResources();

    private:

        /// @brief Lista de todos recursos
        std::vector<std::set<std::string>> _resourcesGeneral;

        /// @brief Lista de todos recursos
        std::vector<std::set<std::string>> _resourcesRutesGeneral;

        /// @brief Vector de rutas de directorios
        std::vector<std::string> _routes { MESH_ROUTE, MATERIALS_ROUTE, UI_ROUTE, FONTS_ROUTE, AUDIO_ROUTE, COMMANDS_ROUTE, DEFAULT_ROUTE, BIN_ROUTE };
    };
}

#endif //UIMANAGER_H
