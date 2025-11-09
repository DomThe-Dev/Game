#pragma once
#include <string>

enum GameState
{
    PLAYING,
    PAUSED,
    MAIN_MENU,
    GAME_OVER
};

struct SceneData
{
    int id_;
    std::string display_name_;
    GameState state_;
};