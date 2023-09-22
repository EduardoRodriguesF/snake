#include "snake.h"
#include "SDL2/SDL_render.h"
#include "game.h"
#include <cmath>

const int SPEED = 1;

Snake::Snake(Direction direction, int x, int y, Uint32 size)
    : direction(direction) {
    for (int i = 0; i < size; i++) {
        SDL_Point part{x, y};

        this->parts.push_back(SDL_Point{x, y});

        switch (direction) {
        case Direction::Up:
            y--;
            break;
        case Direction::Right:
            x++;
            break;
        case Direction::Down:
            y++;
            break;
        case Direction::Left:
            x--;
            break;
        }
    }
}

void Snake::turn(Direction direction) {
    if (this->direction == Direction::Down && direction == Direction::Up ||
        this->direction == Direction::Up && direction == Direction::Down ||
        this->direction == Direction::Left && direction == Direction::Right ||
        this->direction == Direction::Right && direction == Direction::Left) {
        return; // Illegal move
    }

    this->direction = direction;
}

void Snake::grow() { this->parts.push_back(SDL_Point{0, 0}); }

void Snake::update() {
    auto lead = this->parts.front();

    switch (direction) {
    case Direction::Up:
        lead.y--;
        break;
    case Direction::Right:
        lead.x++;
        break;
    case Direction::Down:
        lead.y++;
        break;
    case Direction::Left:
        lead.x--;
        break;
    }

    for (SDL_Point &part : this->parts) {
        SDL_Point aux = part;
        part = lead;
        lead = aux;
    }
}

void Snake::draw(SDL_Renderer *renderer) {
    for (const auto &part : this->parts) {
        SDL_RenderDrawPoint(renderer, part.x, part.y);
    }
}
