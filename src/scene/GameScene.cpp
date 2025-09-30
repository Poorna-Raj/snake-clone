#include "scene/GameScene.h"

GameScene::GameScene() {};

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
    Rectangle foodRec = {food.position.x * cellSize, food.position.y * cellSize, cellSize, cellSize};
    Rectangle snakeHead = {snake.getSnake()[0].x * cellSize, snake.getSnake()[0].y * cellSize, cellSize, cellSize};

    if (CheckCollisionRecs(foodRec, snakeHead))
    {
        snakeEat = true;
    }
    else
    {
        snakeEat = false;
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