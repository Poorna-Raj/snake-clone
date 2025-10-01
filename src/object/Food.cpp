#include "object/Food.h"

Food::Food()
{
    setTexture(LoadTexture("assets/objects/Food.png"));
};

Food::~Food()
{
    UnloadTexture(getTexture());
};

void Food::draw(int cellSize, int offsetY)
{
    Rectangle src = {0.0f, 0.0f, (float)getTexture().width, (float)getTexture().height};
    Rectangle dest = {(float)position.x * cellSize, (float)offsetY + position.y * cellSize, (float)cellSize, (float)cellSize};
    DrawTexturePro(getTexture(), src, dest, {0, 0}, 0.0f, WHITE);
}

void Food::setTexture(Texture2D text)
{
    texture = text;
}

const Texture2D &Food::getTexture() const
{
    return texture;
}