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
    bool isPaused = false;

    const int cellSize = 20;
    const int cellCount = 20;

    double lastUpdatedTime = 0;
    bool snakeEat = false;

    Food food;
    Snake snake;

    Texture2D playBgTexture;

public:
    GameScene();
    ~GameScene();

    void draw();
    void update();
    bool shouldClose();
    void drawPlayArea();
    void drawPauseMenu();
    void updatePauseMenu();

    bool eventTriggerForSnakeUpdate(double interval);
    void checkCollisionSnakeFood();
    void reSpawnFood();
    void checkCollisionSnakeSnake();
    void checkCollisionSnakeBorder();

    void drawStatusBar();

    const Texture2D &getPlayBgTexture() const;
    void setPlayBgTexture(const Texture2D &tex);

    SceneType nextScene();
};