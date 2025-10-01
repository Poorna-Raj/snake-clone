#pragma once
#include "raylib.h"
#include "Scene.h"
#include "SceneType.h"

#include "object/Food.h"
#include "object/Snake.h"

class GameScene : public Scene
{
private:
    bool requestNextScene = false;
    bool shouldExit = false;

    const int cellSize = 20;
    const int cellCount = 20;

    double lastUpdatedTime = 0;
    bool snakeEat = false;

    Food food;
    Snake snake;

public:
    GameScene();
    ~GameScene();

    void draw();
    void update();
    bool shouldClose();

    bool eventTriggerForSnakeUpdate(double interval);
    void checkCollisionSnakeFood();
    void reSpawnFood();
    void checkCollisionSnakeSnake();

    SceneType nextScene();
};