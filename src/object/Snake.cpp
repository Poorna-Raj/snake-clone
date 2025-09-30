#include "object/Snake.h"
#include "raymath.h"

Snake::Snake()
{
    snake.push_back(Vector2{10, 11});
    snake.push_back(Vector2{10, 12});
    snake.push_back(Vector2{10, 13});

    direction = {1, 0};
}

Snake::~Snake() {};

void Snake::draw(int cellSize)
{
    for (Vector2 &seg : snake)
    {
        DrawRectangle(seg.x * cellSize, seg.y * cellSize, cellSize, cellSize, BLUE);
    }
}

void Snake::update(bool grow)
{
    movements(grow);
}

void Snake::movements(bool grow)
{
    snake.insert(snake.begin(), Vector2Add(snake[0], direction));

    if (!grow)
    {
        snake.pop_back();
    }
}

void Snake::takeInputs()
{
    if (IsKeyPressed(KEY_RIGHT) && direction != Vector2{-1, 0})
    {
        direction = {1, 0};
    }

    if (IsKeyPressed(KEY_LEFT) && direction != Vector2{1, 0})
    {
        direction = {-1, 0};
    }

    if (IsKeyPressed(KEY_UP) && direction != Vector2{0, 1})
    {
        direction = {0, -1};
    }

    if (IsKeyPressed(KEY_DOWN) && direction != Vector2{0, -1})
    {
        direction = {0, 1};
    }
}

std::vector<Vector2> Snake::getSnake()
{
    return snake;
}