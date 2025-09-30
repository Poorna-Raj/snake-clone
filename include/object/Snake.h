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

    void draw(int cellSize);
    void update(bool grow);

    void movements(bool grow);
    void takeInputs();
};
