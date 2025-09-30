#pragma once
#include "raylib.h"
#include "Scene.h"
#include "SceneType.h"

class StartScene : public Scene
{
private:
    bool requestNextScene = false;
    bool shouldExit = false;

public:
    StartScene();
    ~StartScene();

    void draw();
    void update();
    bool shouldClose();

    SceneType nextScene();
};