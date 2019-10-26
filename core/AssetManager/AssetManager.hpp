/*

    AssetManager.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 02/10/2019.

    DESCRIPTION:
    AssetManager is a singleton class that loads, stores, manages
    and offloads resources needed by the game. It ensures that
    only one copy of each unique resource is present in memory at
    any given time. It is also responsible for giving the resources
    their unique identifiers which are StringIDs.
    AssetManager usses different types of memory allocations to store
    each resource properly in memory.
    NOTE: This class is not thread safe.

*/

#pragma once
#include "MemorySystem.hpp"
#include "FileSystem.hpp"
#include "StringID.hpp"
#include "Asset.hpp"
#include "Texture.hpp"
#include <cstdint>

class AssetManager {
private:
    StringID assetsPath;
    AssetManager();
    SDL_Texture* loadImageToTexture(const char* filepath);
public:
    static AssetManager& getInstance();
    AssetManager(AssetManager const&) = delete;
    AssetManager& operator=(AssetManager const&) = delete;
    int startUP(const StringID& assetsPath_);
    int shutDown();
};
