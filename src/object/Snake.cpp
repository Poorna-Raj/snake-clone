#include "object/Snake.h"
#include "raymath.h"

Snake::Snake(int cellSize) : cellSize(cellSize)
{
    snake.push_back(Vector2{10, 11});
    snake.push_back(Vector2{10, 12});
    snake.push_back(Vector2{10, 13});

    direction = {1, 0};

    setSnakeBodyTexture(LoadTexture("assets/objects/Snake-Body.png"));
    setSnakeHeadTexture(LoadTexture("assets/objects/Snake-Head.png"));
    setSnakeHeadOrigin({cellSize / 2.0f, cellSize / 2.0f});
}

Snake::~Snake()
{
    UnloadTexture(getSnakeBodyTexture());
    UnloadTexture(getSnakeHeadTexture());
};

void Snake::draw(int offsetY)
{
    for (size_t i = 0; i < getSnake().size(); i++)
    {
        Rectangle dest = {getSnake()[i].x * (float)cellSize + (float)cellSize / 2.0f, offsetY + getSnake()[i].y * (float)cellSize + (float)cellSize / 2.0f, (float)cellSize, (float)cellSize};

        if (i == 0)
        {
            Rectangle src = {0.0f, 0.0f, (float)getSnakeHeadTexture().width, (float)getSnakeHeadTexture().height};
            DrawTexturePro(getSnakeHeadTexture(), src, dest, getSnakeHeadOrigin(), getSnakeHeadRotation(), WHITE);
        }
        else
        {
            Rectangle src = {0.0f, 0.0f, (float)getSnakeBodyTexture().width, (float)getSnakeBodyTexture().height};
            DrawTexturePro(getSnakeBodyTexture(), src, dest, getSnakeHeadOrigin(), 0.0f, WHITE);
        }
    }
}

void Snake::update(bool grow)
{
    movements(grow);
}

void Snake::movements(bool grow)
{
    snake.insert(snake.begin(), Vector2Add(snake[0], getDirection()));

    if (!grow)
    {
        snake.pop_back();
    }
}

void Snake::takeInputs()
{
    if (IsKeyPressed(KEY_RIGHT) && direction != Vector2{-1, 0})
    {
        setDirection({1, 0});
        setSnakeHeadRotation(90.0f);
    }

    if (IsKeyPressed(KEY_LEFT) && direction != Vector2{1, 0})
    {
        setDirection({-1, 0});
        setSnakeHeadRotation(270.0f);
    }

    if (IsKeyPressed(KEY_UP) && direction != Vector2{0, 1})
    {
        setDirection({0, -1});
        setSnakeHeadRotation(0.0f);
    }

    if (IsKeyPressed(KEY_DOWN) && direction != Vector2{0, -1})
    {
        setDirection({0, 1});
        setSnakeHeadRotation(180.0f);
    }
}

std::vector<Vector2> &Snake::getSnake()
{
    return snake;
}

const Texture2D &Snake::getSnakeBodyTexture() const
{
    return snakeBodyTexture;
}

void Snake::setSnakeBodyTexture(const Texture2D &tex)
{
    snakeBodyTexture = tex;
}

const Texture2D &Snake::getSnakeHeadTexture() const
{
    return snakeHeadTexture;
}

void Snake::setSnakeHeadTexture(const Texture2D &tex)
{
    snakeHeadTexture = tex;
}

const float &Snake::getSnakeHeadRotation() const
{
    return snakeHeadRotation;
}

const Vector2 &Snake::getSnakeHeadOrigin() const
{
    return snakeHeadOrigin;
}

void Snake::setSnakeHeadRotation(const float rotation)
{
    snakeHeadRotation = rotation;
}

void Snake::setSnakeHeadOrigin(const Vector2 &origin)
{
    snakeHeadOrigin = origin;
}

const int Snake::getCellSize() const
{
    return cellSize;
}

void Snake::setCellSize(const int size)
{
    cellSize = size;
}

const Vector2 &Snake::getDirection() const
{
    return direction;
}

void Snake::setDirection(const Vector2 &dir)
{
    direction = dir;
}