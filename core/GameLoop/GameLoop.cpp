/*

    GameLoop.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 31/10/2019.

*/

#include "GameLoop.hpp"

GameLoop::GameLoop()  {}

GameLoop::~GameLoop() {}

GameLoop& GameLoop::getInstance() {
    static GameLoop instance;
    return instance;
}

uint32_t GameLoop::startUP(uint8_t fps) {
    msPerUpdate = 1.0f / fps;
    isRunning   = true;
    return 0;
}

void GameLoop::run() {
    timer.reset();
    double lag = 0.0f;
    double interpolation;

    /*  for demonstration purposes only, might delete later :P */
    SDL_Renderer* renderer = SDLModule::getInstance().getRenderer();
    Texture* logoTex = AssetManager::getInstance().loadAssetAs<Texture>(SID("logoBlack.png"));
    SDL_Event event;

    while (isRunning) {
        lag += timer.timePassed();
        timer.reset();

        /*  input handling          */
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
                isRunning = false;
            } else {
                inputHandler.processInput(event);
            }
        }

        /*  update handling         */
        while (lag >= msPerUpdate) {
            /*  command processing example  */
            for (auto& cmd : inputHandler.getMainDevice()->popCommands()) {
                printf("%s\n", cmd.getPtr());
            }
            lag -= msPerUpdate;
        }
        interpolation = lag / msPerUpdate;
        /*  render handling         */
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, logoTex->texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
}

uint32_t GameLoop::shutDown() {
    isRunning = false;
    return 0;
}
