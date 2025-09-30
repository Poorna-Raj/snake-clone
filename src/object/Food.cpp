#include "object/Food.h"

Food::Food() {};

Food::~Food() {};

void Food::draw(int cellSize)
{
    DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, YELLOW);
}