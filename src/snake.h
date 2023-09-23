#pragma once

#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_stdinc.h"
#include <vector>

enum class Direction {
    Up,
    Right,
    Down,
    Left,
};

class Snake {
public:
    Snake(Direction direction, int x, int y, Uint32 size);
    void turn(Direction direction);
    void grow();
    void update();
    void draw(SDL_Renderer* renderer);
    std::vector<SDL_Point> parts_pos() const;
    SDL_Point head() const;
private:
    Direction direction;
    std::vector<SDL_Point> parts;
};
