#pragma once
#include "Scene.hpp"
#include "TextureManager.hpp"

class Level2: public Scene {
public:
    Level2(Window&, TextureManager&);
    ~Level2();

    virtual void draw() override;
    virtual void update(float dt) override;

protected:
    int mapWidth;
    int mapHeight;
    int tiles[1000] = {0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 1, 2, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 1, 2, 2, 3, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 15, 16, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 15, 16, 16, 17, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 38, 0, 38, 0, 38, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 5, 2, 2, 3, 0, 0, 0, 6, 7, 8, 9, 10, 0, 0, 0, 18, 0, 0, 0, 6, 7, 8, 7, 8, 9, 24, 0, 0, 18, 0, 0, 38, 0, 38, 0, 0, 0, 15, 16, 16, 18, 16, 16, 17, 0, 0, 10, 20, 21, 22, 23, 0, 0, 0, 0, 32, 0, 0, 24, 20, 21, 22, 21, 22, 23, 0, 0, 0, 18, 0, 6, 7, 8, 7, 9, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 34, 35, 36, 37, 10, 0, 0, 0, 46, 0, 0, 0, 34, 35, 36, 22, 22, 23, 0, 0, 0, 18, 0, 20, 21, 22, 21, 23, 10, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 20, 22, 23, 24, 0, 0, 18, 0, 34, 35, 36, 35, 37, 0, 0, 0, 0, 0, 46, 0, 0, 0, 1, 2, 2, 2, 2, 19, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0, 0, 0, 20, 22, 23, 0, 0, 0, 18, 0, 10, 0, 10, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 16, 16, 16, 16, 18, 16, 16, 16, 16, 16, 16, 16, 16, 17, 0, 0, 0, 20, 22, 23, 24, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 36, 37, 0, 0, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 0, 38, 0, 38, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 4, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 0, 0, 0, 6, 7, 8, 7, 8, 7, 9, 0, 0, 0, 0, 0, 18, 0, 0, 6, 7, 8, 9, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 16, 17, 0, 0, 4, 20, 21, 22, 21, 22, 21, 23, 10, 0, 0, 0, 0, 18, 0, 0, 20, 21, 22, 23, 10, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 34, 35, 36, 35, 36, 35, 37, 0, 0, 0, 0, 0, 18, 0, 0, 34, 35, 36, 37, 0, 0, 0, 1, 5, 2, 2, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 10, 0, 10, 0, 10, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 32, 16, 16, 16, 17, 0, 0, 1, 2, 2, 2, 19, 2, 2, 2, 2, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0, 0, 0, 0, 0, 15, 16, 16, 16, 18, 16, 16, 16, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 21, 22, 23, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 10, 34, 35, 36, 37, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 7, 8, 9, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0, 0, 0, 0, 0, 0, 10, 20, 21, 22, 23, 10, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 34, 35, 36, 37, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 5, 3, 0, 0, 0, 10, 20, 21, 22, 23, 10, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 15, 16, 16, 16, 16, 16, 32, 17, 0, 0, 0, 0, 34, 35, 36, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0};
};