#pragma once
#include "raylib.h"

class Food
{
public:
    Vector2 position = {5, 6};

    Food();
    ~Food();

    void draw(int cellSize);
};