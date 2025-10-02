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

public:
    Snake();
    ~Snake();

    void draw(int cellSize, int offsetY);
    void update(bool grow);

    void movements(bool grow);
    void takeInputs();

    std::vector<Vector2> &getSnake();
    const Texture2D &getSnakeBodyTexture() const;
    const Texture2D &getSnakeHeadTexture() const;

    void setSnakeBodyTexture(const Texture2D &tex);
    void setSnakeHeadTexture(const Texture2D &tex);
};
