/*

    SystemManager.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 13/09/2019.

    DESCRIPTION:
    System Manager is a singleton object that
    starts up, controlls and shuts down
    every chickchirik game engine subsystem.
    NOTE: This class is not thread safe.

*/

#pragma once
#include "SDLModule.hpp"
#include "StringID.hpp"
#include "FileSystem.hpp"
#include "ConfigManager.hpp"
#include "MemorySystem.hpp"
#include "AssetManager.hpp"
#include "InputHandler.hpp"
#include "GameLoop.hpp"
#include <iostream>
#include <cstdio>


class SystemManager {
private:
    FileSystem&     fileSys = FileSystem::getInstance();
    ConfigManager&  conMan  = ConfigManager::getInstance();
    MemorySystem&   memSys  = MemorySystem::getInstance();
    AssetManager&   assMan  = AssetManager::getInstance();
    SDLModule&      sdl     = SDLModule::getInstance();
    InputHandler&   inputHandler = InputHandler::getInstance();
    GameLoop&       gloop   = GameLoop::getInstance();
    SystemManager();
    uint32_t initMemorySystem(bpt::ptree& config);
public:
    SystemManager(SystemManager const&)            = delete;
    SystemManager& operator=(SystemManager const&) = delete;
    static SystemManager& getInstance();
    uint32_t BigInit();                                             /*  All subsystems are started here     */
    uint32_t BigShutDown();                                         /*  All subsystems are shutted here     */
};
