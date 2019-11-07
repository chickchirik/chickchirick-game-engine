/*

    InputHandler.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 03/11/2019.

    DESCRIPTION:

*/

#pragma once
#include "MemorySystem.hpp"
#include "PropertyTree.hpp"
#include "SDLModule.hpp"
#include "Gamepad.hpp"
#include "Vector.hpp"
#include <cstdint>
#include <cstdio>

class InputHandler {
private:
    MemorySystem&       mem = MemorySystem::getInstance();
    Vector<Gamepad*>    deviceRegistry;
    InputHandler();
public:
    InputHandler(InputHandler const&)            = delete;
    InputHandler& operator=(InputHandler const&) = delete;
    static InputHandler& getInstance();
    ~InputHandler();
    uint32_t startUP(bpt::ptree& config);
    uint32_t shutDown();
};