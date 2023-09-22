#pragma once

#include <SDL2/SDL.h>
#include <string>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

const float SCALE = 3.0;

const int FPS = 60;
const int FRAME_MS = 1000 / FPS;

const int CANVAS_WIDTH = WINDOW_WIDTH / SCALE;
const int CANVAS_HEIGHT = WINDOW_HEIGHT / SCALE;

class Game {
public:
    Game();
    ~Game();
    void update();
    void draw();
    bool is_running() const;
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
};