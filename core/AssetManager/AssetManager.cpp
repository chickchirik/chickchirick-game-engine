/*

    AssetManager.cpp
    chickchirick-game-engine

    Created by <chickchirik> on 02/10/2019.

*/

#include "AssetManager.hpp"

AssetManager::AssetManager()  {}

AssetManager& AssetManager::getInstance() {
    static AssetManager instance;
    return instance;
}

int AssetManager::startUP(const StringID& assetsPath_) {
    this->assetsPath = assetsPath_;
    return 0;
}

int AssetManager::shutDown() {  return 0;  }

Asset* AssetManager::getAsset(const StringID& name) {
    Asset* result = nullptr;
    if (resRegistry.count(name) == 1) {
        result = resRegistry.at(name);
    }
    return result;
}

template <>
void AssetManager::loadAssetAsType<Texture>(Texture* asset, const StringID& name) {
    auto&  fs  = FileSystem::getInstance();
    auto&  sdl = SDLModule::getInstance();
    string filepath = fs.getAssetsPath().getStr() + name.getStr();
    SDL_Surface* SDLsurface = fs.loadIMG(filepath.c_str());
    SDL_Texture* SDLtexture = SDL_CreateTextureFromSurface(sdl.getRenderer(), SDLsurface);
    SDL_FreeSurface(SDLsurface);

    asset->texture = SDLtexture;
    asset->id = name;
}

template <>
Texture* AssetManager::loadAssetAs<Texture>(const StringID& name) {
    Texture* result = nullptr;
    if (resRegistry.count(name) == 0) {
        result = CAST(Texture*, mem.stalloc(sizeof(Texture)));
        this->loadAssetAsType<Texture>(result, name);
        resRegistry[name] = STCAST(Asset*, result);
    }
    return result;
}

template <>
Texture* AssetManager::loadConstantAssetAs<Texture>(const StringID& name) {
    printf("loadConstantAssetAs<Texture>\nname: %s\n", name.getPtr());
    Texture* result = nullptr;
    if (resRegistry.count(name) == 0) {
        result = CAST(Texture*, mem.allocLSR(sizeof(Texture)));
        this->loadAssetAsType<Texture>(result, name);
        resRegistry[name] = STCAST(Asset*, result);
    }
    return result;
}
