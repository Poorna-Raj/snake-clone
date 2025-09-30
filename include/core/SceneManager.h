#pragma once
#include "raylib.h"
#include <memory>
#include <iostream>
#include "scene/Scene.h"
#include "scene/SceneType.h"

class SceneManager
{
private:
    std::unique_ptr<Scene> currentScene;
    SceneType currentType;

public:
    SceneManager();
    ~SceneManager();

    void switchScene(SceneType type);
    void draw();
    void update();
    bool shouldClose() const;
};