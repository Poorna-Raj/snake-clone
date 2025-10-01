#pragma once
#include "raylib.h"

class Food
{
private:
    Texture2D texture;

public:
    Vector2 position = {5, 6};

    Food();
    ~Food();

    void draw(int cellSize, int offsetY);

    void setTexture(Texture2D text);
    const Texture2D &getTexture() const;
};