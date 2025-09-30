#pragma once
#include "raylib.h"
#include "Scene.h"
#include "SceneType.h"

#include "object/Food.h"

class GameScene : public Scene
{
private:
    bool requestNextScene = false;
    bool shouldExit = false;

    const int cellSize = 30;
    const int cellCount = 25;

    Food food;

public:
    GameScene();
    ~GameScene();

    void draw();
    void update();
    bool shouldClose();

    SceneType nextScene();
};