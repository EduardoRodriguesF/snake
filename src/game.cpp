#include "game.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_render.h"
#include <stdexcept>

Game::Game() : running(true) {
    this->window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
                                    WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    if (this->window == NULL) {
        throw std::runtime_error("Failed to create window");
    }

    this->renderer = SDL_CreateRenderer(
        this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->renderer == NULL) {
        throw std::runtime_error("Failed to create renderer");
    }
}

Game::~Game() {
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);

    SDL_Quit();
}

void Game::update() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_QUIT:
            this->running = false;
            break;
        }
    }
}

void Game::draw() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

bool Game::is_running() const { return this->running; }
