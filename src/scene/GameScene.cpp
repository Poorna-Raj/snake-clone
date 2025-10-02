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
}

void GameScene::update()
{
    snake.takeInputs();
    if (eventTriggerForSnakeUpdate(0.2))
    {
        snake.update(snakeEat);
        checkCollisionSnakeFood();
        checkCollisionSnakeSnake();
        checkCollisionSnakeBorder();
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
    DrawText(TextFormat("Player - %d", (int)snake.getSnake().size() - 3), 10, offsetY / 2 - 10, 20, WHITE);
}

void GameScene::drawPlayArea()
{
    Rectangle src = {0.0f, 0.0f, (float)getPlayBgTexture().width, (float)getPlayBgTexture().height};
    Rectangle dest = {0.0f, (float)offsetY, (float)(cellCount * cellSize), (float)(cellCount * cellSize)};
    DrawTexturePro(getPlayBgTexture(), src, dest, {0, 0}, 0.0f, WHITE);
    // DrawRectangle(0, offsetY, cellCount * cellSize, cellCount * cellSize, DARKGRAY);
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