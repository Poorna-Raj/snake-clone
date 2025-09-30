#pragma once
#include "raylib.h"

class Scene
{
public:
    virtual ~Scene() = default;
    virtual void update() = 0;
    virtual void draw() = 0;

    virtual bool shouldClose() { return false; };
};