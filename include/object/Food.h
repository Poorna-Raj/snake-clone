#pragma once
#include "raylib.h"

class Food
{
private:
    Texture2D texture;
    Vector2 position = {5, 6};

public:
    Food();
    ~Food();

    void draw(int cellSize, int offsetY);

    void setTexture(const Texture2D &text);
    void setPosition(const Vector2 &pos);

    const Texture2D &getTexture() const;
    Vector2 getPosition() const;
};