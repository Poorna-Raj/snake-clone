#include "scene/EndScene.h"

EndScene::EndScene()
{
    setBgTexture(LoadTexture("assets/backgrounds/game-over.png"));
};

EndScene::~EndScene()
{
    UnloadTexture(getBgTexture());
};

void EndScene::draw()
{
    Rectangle src = {0.0f, 0.0f, (float)getBgTexture().width, (float)getBgTexture().height};
    Rectangle dest = {0.0f, 0.0f, (float)GetScreenWidth(), (float)GetScreenHeight()};
    DrawTexturePro(getBgTexture(), src, dest, {0, 0}, 0.0f, WHITE);

    drawMenu();
}

void EndScene::update()
{
    updateMenu();
    if (IsKeyPressed(KEY_Q))
    {
        shouldExit = true;
    }

    if (IsKeyPressed(KEY_ENTER))
    {
        requestNextScene = true;
    }
}

void EndScene::drawMenu()
{
    Rectangle playBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 - 30.0f, 120, 40};
    bool hoveringPlay = CheckCollisionPointRec(GetMousePosition(), playBtn);
    DrawRectangleRec(playBtn, hoveringPlay ? Color{60, 120, 255, 255} : Color{20, 60, 160, 255});
    DrawText("Play", (int)playBtn.x + 40, (int)playBtn.y + 10, 20, Color{255, 255, 255, 255});

    Rectangle exitBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 + 30.0f, 120, 40};
    bool hoveringExit = CheckCollisionPointRec(GetMousePosition(), exitBtn);
    DrawRectangleRec(exitBtn, hoveringExit ? Color{255, 60, 60, 255} : Color{160, 20, 20, 255});
    DrawText("Exit", (int)exitBtn.x + 40, (int)exitBtn.y + 10, 20, Color{255, 255, 255, 255});
}

void EndScene::updateMenu()
{
    Rectangle playBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 - 30.0f, 120, 40};
    if (CheckCollisionPointRec(GetMousePosition(), playBtn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        requestNextScene = true;
    }

    Rectangle exitBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 + 30.0f, 120, 40};
    if (CheckCollisionPointRec(GetMousePosition(), exitBtn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        shouldExit = true;
    }
}

const Texture2D &EndScene::getBgTexture() const
{
    return background;
}

void EndScene::setBgTexture(const Texture2D &tex)
{
    background = tex;
}

bool EndScene::shouldClose()
{
    return shouldExit;
}

SceneType EndScene::nextScene()
{
    return requestNextScene ? SceneType::START : SceneType::NONE;
}