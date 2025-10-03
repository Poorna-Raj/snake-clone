#include "scene/GameScene.h"

int offsetY;

GameScene::GameScene() : snake(cellSize)
{
    reSpawnFood();
    offsetY = (GetScreenHeight() - (cellCount * cellSize));
    setPlayBgTexture(LoadTexture("assets/backgrounds/Game-Bg.png"));
};

GameScene::~GameScene()
{
    UnloadTexture(getPlayBgTexture());
};

void GameScene::draw()
{
    drawPlayArea();
    drawStatusBar();

    food.draw(cellSize, offsetY);
    snake.draw(offsetY);

    if (isPaused)
    {
        drawPauseMenu();
    }
}

void GameScene::update()
{
    if (!isPaused)
    {
        snake.takeInputs();
        if (eventTriggerForSnakeUpdate(0.2))
        {
            snake.update(snakeEat);
            checkCollisionSnakeFood();
            checkCollisionSnakeSnake();
            checkCollisionSnakeBorder();
        }
    }
    else
    {
        updatePauseMenu();
    }
    if (IsKeyPressed(KEY_Q))
    {
        shouldExit = true;
    }

    if (IsKeyPressed(KEY_ENTER))
    {
        requestNextScene = true;
    }

    if (IsKeyPressed(KEY_TAB))
    {
        isPaused = !isPaused;
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
    Rectangle foodRec = {food.getPosition().x * (float)cellSize, offsetY + food.getPosition().y * (float)cellSize, (float)cellSize, (float)cellSize};
    Rectangle snakeHead = {snake.getSnake()[0].x * (float)cellSize, offsetY + snake.getSnake()[0].y * (float)cellSize, (float)cellSize, (float)cellSize};

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
    Vector2 newPosition = {
        (float)GetRandomValue(1, cellCount - 2),
        (float)GetRandomValue(1, cellCount - 2)};

    food.setPosition(newPosition);
}

void GameScene::checkCollisionSnakeSnake()
{
    Rectangle snakeHead = {snake.getSnake()[0].x * (float)cellSize, offsetY + snake.getSnake()[0].y * (float)cellSize, (float)cellSize, (float)cellSize};
    const auto &segments = snake.getSnake();
    for (size_t i = 1; i < segments.size(); i++)
    {
        Rectangle segmentRec = {segments[i].x * cellSize,
                                offsetY + segments[i].y * cellSize,
                                (float)cellSize,
                                (float)cellSize};
        if (CheckCollisionRecs(snakeHead, segmentRec))
        {
            requestNextScene = true;
            break;
        }
    }
}

void GameScene::checkCollisionSnakeBorder()
{
    const Vector2 &snakeHead = snake.getSnake()[0];

    if (snakeHead.x <= 0 || snakeHead.x >= cellCount - 1 || snakeHead.y <= 0 || snakeHead.y >= cellCount - 1)
    {
        requestNextScene = true;
    }
}

void GameScene::drawStatusBar()
{
    DrawRectangle(0, 0, GetScreenWidth(), offsetY, BLACK);
    DrawText("Score = ", 10, offsetY / 2 - 10, 20, WHITE);
    DrawTexture(food.getTexture(), 100, offsetY / 2 - 10, WHITE);
    DrawText(TextFormat("x %d", (int)snake.getSnake().size() - 3), 130, offsetY / 2 - 10, 20, WHITE);
}

void GameScene::drawPlayArea()
{
    Rectangle src = {0.0f, 0.0f, (float)getPlayBgTexture().width, (float)getPlayBgTexture().height};
    Rectangle dest = {0.0f, (float)offsetY, (float)(cellCount * cellSize), (float)(cellCount * cellSize)};
    DrawTexturePro(getPlayBgTexture(), src, dest, {0, 0}, 0.0f, WHITE);
}

void GameScene::drawPauseMenu()
{
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), {0, 0, 0, 150});
    DrawRectangle(GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 150, 300, 300, {0, 0, 0, 200});

    DrawText("GAME PAUSED", GetScreenWidth() / 2 - 110, GetScreenHeight() / 2 - 100, 30, {255, 255, 255, 255});

    Rectangle resumeBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 - 50.0f, 120, 40};
    bool hoveringResume = CheckCollisionPointRec(GetMousePosition(), resumeBtn);
    DrawRectangleRec(resumeBtn, hoveringResume ? Color{60, 120, 255, 255} : Color{20, 60, 160, 255});
    DrawText("Resume", (int)resumeBtn.x + 23, (int)resumeBtn.y + 10, 20, Color{255, 255, 255, 255});

    Rectangle exitBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 + 30.0f, 120, 40};
    bool hoveringExit = CheckCollisionPointRec(GetMousePosition(), exitBtn);
    DrawRectangleRec(exitBtn, hoveringExit ? Color{255, 60, 60, 255} : Color{160, 20, 20, 255});
    DrawText("Exit", (int)exitBtn.x + 40, (int)exitBtn.y + 10, 20, Color{255, 255, 255, 255});
}

void GameScene::updatePauseMenu()
{
    Rectangle resumeBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 - 50.0f, 120, 40};
    if (CheckCollisionPointRec(GetMousePosition(), resumeBtn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        isPaused = !isPaused;
    }

    Rectangle exitBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 + 30.0f, 120, 40};
    if (CheckCollisionPointRec(GetMousePosition(), exitBtn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        shouldExit = true;
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

const Texture2D &GameScene::getPlayBgTexture() const
{
    return playBgTexture;
}

void GameScene::setPlayBgTexture(const Texture2D &tex)
{
    playBgTexture = tex;
}