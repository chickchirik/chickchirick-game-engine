/*
    System Manager is a singleton object that
    starts up, controlls and shuts down
    every chickchirik game engine subsystem.
*/


#pragma once
#include <SDL.h>
#include <SDL_image.h>

class SystemManager {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    int BigInit();
    int BigShutDown();
};
