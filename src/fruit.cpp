#include "fruit.h"

Fruit::Fruit(int x, int y) {
    this->pos = SDL_Point { x, y };
};

SDL_Point Fruit::position() const { return this->pos; }
void Fruit::set_position(SDL_Point pos) { this->pos = pos; }

void Fruit::draw(SDL_Renderer *renderer) {
    SDL_RenderDrawPoint(renderer, pos.x, pos.y);
}
