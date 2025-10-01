#pragma once
#include "raylib.h"
#include <vector>

class Snake
{
private:
    std::vector<Vector2> snake;
    Vector2 direction;

public:
    Snake();
    ~Snake();

    void draw(int cellSize, int offsetY);
    void update(bool grow);

    void movements(bool grow);
    void takeInputs();

    std::vector<Vector2> &getSnake();
};
