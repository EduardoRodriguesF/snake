#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "SDL2/SDL_stdinc.h"
#include "snake.h"
#include "fruit.h"
#include "utils.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

const float SCALE = 6.0;

const int FPS = 24;
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
    void handle_collision();
    void gen_fruit();
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
    Snake snake;
    Fruit fruit;
};
