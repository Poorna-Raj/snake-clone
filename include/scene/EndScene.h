#pragma once
#include "raylib.h"
#include "Scene.h"
#include "SceneType.h"

class EndScene : public Scene
{
private:
    bool requestNextScene = false;
    bool shouldExit = false;
    Texture2D background;

public:
    EndScene();
    ~EndScene();

    void draw();
    void update();
    bool shouldClose();
    void drawMenu();
    void updateMenu();

    SceneType nextScene();

    const Texture2D &getBgTexture() const;
    void setBgTexture(const Texture2D &tex);
};