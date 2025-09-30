#include "scene/StartScene.h"

StartScene::StartScene() {};

StartScene::~StartScene() {};

void StartScene::draw()
{
    DrawText("Start Scene", 100, 100, 20, GREEN);
    DrawText("Press Q to exit", 100, 130, 20, RED);
    DrawText("Press ENTER to play", 100, 160, 20, BLUE);
}

void StartScene::update()
{
    if (IsKeyPressed(KEY_Q))
    {
        shouldExit = true;
    }

    if (IsKeyPressed(KEY_ENTER))
    {
        requestNextScene = true;
    }
}

bool StartScene::shouldClose()
{
    return shouldExit;
}

SceneType StartScene::nextScene()
{
    return requestNextScene ? SceneType::GAMEPLAY : SceneType::NONE;
}