#pragma once
#include "raylib.h"
#include "Scene.h"
#include "SceneType.h"

class GameScene : public Scene
{
private:
    bool requestNextScene = false;
    bool shouldExit = false;

public:
    GameScene();
    ~GameScene();

    void draw();
    void update();
    bool shouldClose();

    SceneType nextScene();
};