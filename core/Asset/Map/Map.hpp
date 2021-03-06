/*

    Map.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 26/10/2019.

    DESCRIPTION:
    Map class to handle level/chunk/sequence in-game layout.
    NOTE: This class is not thread safe.

*/

#pragma once
#include "Asset.hpp"

class Map : public Asset {
private:
public:
    Map();
    ~Map();
    inline Type getType() const override { return Asset::Type::Map; }
};
