#pragma once
#include "raylib.h"
#include "Scene.h"
#include "SceneType.h"

class StartScene : public Scene
{
private:
    bool requestNextScene = false;
    bool shouldExit = false;
    Texture2D background;

public:
    StartScene();
    ~StartScene();

    void draw();
    void update();
    bool shouldClose();
    void drawMenu();
    void updateMenu();

    SceneType nextScene();

    const Texture2D &getBgTexture() const;
    void setBgTexture(const Texture2D &tex);
};