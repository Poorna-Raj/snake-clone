#pragma once
#include "raylib.h"
#include <vector>

class Snake
{
private:
    std::vector<Vector2> snake;
    Vector2 direction;
    Texture2D snakeHeadTexture;
    Texture2D snakeBodyTexture;
    Texture2D snakeTailTexture;

    float snakeHeadRotation = 0.0f;
    Vector2 snakeHeadOrigin;

    int cellSize;

public:
    Snake(int cellSize);
    ~Snake();

    void draw(int offsetY);
    void update(bool grow);

    void movements(bool grow);
    void takeInputs();
    float calculateTailRotation(Vector2 &tail, Vector2 &before);

    std::vector<Vector2> &getSnake();
    const Texture2D &getSnakeBodyTexture() const;
    const Texture2D &getSnakeHeadTexture() const;
    const Texture2D &getSnakeTailTexture() const;
    const float &getSnakeHeadRotation() const;
    const Vector2 &getSnakeHeadOrigin() const;
    const int getCellSize() const;
    const Vector2 &getDirection() const;

    void setSnakeBodyTexture(const Texture2D &tex);
    void setSnakeHeadTexture(const Texture2D &tex);
    void setSnakeTailTexture(const Texture2D &tex);
    void setSnakeHeadRotation(const float rotation);
    void setSnakeHeadOrigin(const Vector2 &origin);
    void setCellSize(const int size);
    void setDirection(const Vector2 &dir);
};
