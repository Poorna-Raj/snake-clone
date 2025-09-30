#include "scene/GameScene.h"

GameScene::GameScene() {};

GameScene::~GameScene() {};

void GameScene::draw()
{
    DrawText("Game Scene", 100, 100, 20, GREEN);
    DrawText("Press Q to exit", 100, 130, 20, RED);
    DrawText("Press ENTER to play", 100, 160, 20, BLUE);
}

void GameScene::update()
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

bool GameScene::shouldClose()
{
    return shouldExit;
}

SceneType GameScene::nextScene()
{
    return requestNextScene ? SceneType::START : SceneType::NONE;
}