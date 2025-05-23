#!/bin/zsh

# Especificamos las direcciones que vamos a usar
# COMPILEDIR es la dirección donde se encuentra el source de OGRE que vamos a compilar
# BUILDDIR es la dirección en la que vamos a volcar la build de OGRE

COMPILEDIR=../../src
BUILDDIR=./build
FILE=chkbuild.EDENBUILD
OGREBUILDVER=1.3
COMPILE=1
BINFOLDER=./../../../../bin

if test -f "$FILE"
then
    CHKBUILDVER=$(<$FILE)
    if [[ $OGREBUILDVER == "$CHKBUILDVER" ]]
    then
        COMPILE=0
    else
        rm -rf $BUILDDIR
        echo $OGREBUILDVER >$FILE
    fi
else
    rm -rf $BUILDDIR
    echo $OGREBUILDVER >$FILE
fi

if [[ $COMPILE == 1 ]]
then
    # Creamos la carpeta en la ruta de BUILDDIR
    mkdir $BUILDDIR
    cd "$BUILDDIR"

    architecture=$(uname -m)
    mkdir "$architecture"
    cd "$architecture"

    # Generamos con CMake a partir de la carpeta con el Src de OGRE la solución de XCode con las tags correspondientes
    cmake -G "Xcode" -DCMAKE_OSX_ARCHITECTURES="$architecture" -DOGRE_BUILD_COMPONENT_BULLET:BOOL=0 -DOGRE_BUILD_COMPONENT_BITES:BOOL=0 -DOGRE_BUILD_PLUGIN_ASSIMP:BOOL=0 -DOGRE_BUILD_PLUGIN_DOT_SCENE:BOOL=0 -DOGRE_BUILD_SAMPLES:BOOL=0 -DOGRE_INSTALL_SAMPLES:BOOL=0 -DOGRE_BUILD_TOOLS:BOOL=0 -DOGRE_INSTALL_TOOLS:BOOL=0 -DOGRE_BUILD_RENDERSYSTEM_D3D11:BOOL=0 -DOGRE_BUILD_RENDERSYSTEM_D3D9:BOOL=0 -DOGRE_BUILD_RENDERSYSTEM_GL3PLUS:BOOL=0 -DOGRE_BUILD_RENDERSYSTEM_GLES2:BOOL=0 -DOGRE_BUILD_RENDERSYSTEM_TINY:BOOL=0 -DOGRE_BUILD_RENDERSYSTEM_VULKAN:BOOL=0 -DOGRE_BUILD_LIBS_AS_FRAMEWORKS:BOOL=0 $COMPILEDIR

    # Compilamos OGRE tanto en Debug como en Release
    xcodebuild -project OGRE.xcodeproj -configuration Debug
    xcodebuild -project OGRE.xcodeproj -configuration Release

    cp -r ./bin/plugins.cfg "$BINFOLDER"
    touch "$BINFOLDER"/resources.cfg
    echo "[General]" >> "$BINFOLDER"/resources.cfg
    echo "FileSystem=./assets/" >> "$BINFOLDER"/resources.cfg
    echo "FileSystem=./assets/mesh/" >> "$BINFOLDER"/resources.cfg
	echo "FileSystem=./assets/fonts/" >> "$BINFOLDER"/resources.cfg
	echo "FileSystem=./assets/default" >> "$BINFOLDER"/resources.cfg

    cd ../..

    echo OGRE compilado
else
    echo ULTIMA VERSION DE OGRE DETECTADA, no es necesario compilar
fi
