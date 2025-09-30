#include "scene/GameScene.h"

GameScene::GameScene()
{
    reSpawnFood();
};

GameScene::~GameScene() {};

void GameScene::draw()
{
    food.draw(cellSize);
    snake.draw(cellSize);
    DrawText("Game Scene", 100, 100, 20, GREEN);
    DrawText("Press Q to exit", 100, 130, 20, RED);
    DrawText("Press ENTER to play", 100, 160, 20, BLUE);
}

void GameScene::update()
{
    snake.takeInputs();
    if (eventTriggerForSnakeUpdate(0.2))
    {
        snake.update(snakeEat);
        checkCollisionSnakeFood();
    }
    if (IsKeyPressed(KEY_Q))
    {
        shouldExit = true;
    }

    if (IsKeyPressed(KEY_ENTER))
    {
        requestNextScene = true;
    }
}

bool GameScene::eventTriggerForSnakeUpdate(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdatedTime >= interval)
    {
        lastUpdatedTime = currentTime;
        return true;
    }
    return false;
}

void GameScene::checkCollisionSnakeFood()
{
    Rectangle foodRec = {food.position.x * (float)cellSize, food.position.y * (float)cellSize, (float)cellSize, (float)cellSize};
    Rectangle snakeHead = {snake.getSnake()[0].x * (float)cellSize, snake.getSnake()[0].y * (float)cellSize, (float)cellSize, (float)cellSize};

    if (CheckCollisionRecs(foodRec, snakeHead))
    {
        snakeEat = true;
        reSpawnFood();
    }
    else
    {
        snakeEat = false;
    }
}

void GameScene::reSpawnFood()
{
    food.position.x = (float)GetRandomValue(0, cellCount);
    food.position.y = (float)GetRandomValue(0, cellCount);
}

bool GameScene::shouldClose()
{
    return shouldExit;
}

SceneType GameScene::nextScene()
{
    return requestNextScene ? SceneType::START : SceneType::NONE;
}