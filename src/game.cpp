#include "game.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_keycode.h"
#include "SDL2/SDL_render.h"
#include "fruit.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <stdexcept>

Game::Game()
    : running(true), snake(Direction::Right, 12, CANVAS_HEIGHT / 2, 10),
      fruit(0, 0) {
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

    SDL_RenderSetLogicalSize(renderer, CANVAS_WIDTH, CANVAS_HEIGHT);

    gen_fruit();
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
        case SDL_KEYDOWN:
            switch (e.key.keysym.sym) {
            case SDLK_UP:
                snake.turn(Direction::Up);
                break;
            case SDLK_RIGHT:
                snake.turn(Direction::Right);
                break;
            case SDLK_DOWN:
                snake.turn(Direction::Down);
                break;
            case SDLK_LEFT:
                snake.turn(Direction::Left);
                break;
            }
            break;
        }
    }

    this->handle_collision();

    snake.update();
}

void Game::gen_fruit() {
    SDL_Point location;
    auto snake_locations = this->snake.parts_pos();
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int>  dist_width(0, CANVAS_WIDTH - 1);
    std::uniform_int_distribution<int>  dist_height(0, CANVAS_HEIGHT - 1);

    do {
        location.x = dist_width(generator);
        location.y = dist_height(generator);
    } while (std::find(snake_locations.begin(), snake_locations.end(),
                       location) != snake_locations.end());

    this->fruit.set_position(location);
}

void Game::handle_collision() {
    if (this->snake.head() == this->fruit.position()) {
        snake.grow();
        gen_fruit();
    }
}

void Game::draw() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    snake.draw(renderer);
    fruit.draw(renderer);

    SDL_RenderPresent(renderer);
}

bool Game::is_running() const { return this->running; }
