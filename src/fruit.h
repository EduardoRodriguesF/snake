#pragma once

#include "SDL2/SDL_render.h"

class Fruit {
public:
    Fruit(int x, int y);
    SDL_Point position() const;
    void set_position(SDL_Point pos);
    void draw(SDL_Renderer* renderer);
private:
    SDL_Point pos;
};
