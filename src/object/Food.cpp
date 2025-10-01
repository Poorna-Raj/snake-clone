#include "object/Food.h"

Food::Food() {};

Food::~Food() {};

void Food::draw(int cellSize, int offsetY)
{
    DrawRectangle((int)position.x * cellSize, offsetY + (int)position.y * cellSize, cellSize, cellSize, YELLOW);
}