#include "SDL2/SDL_timer.h"
#include "game.h"
#include <memory>

int main() {
    auto game = std::make_unique<Game>();

    Uint32 delta = 0;
    while (game->is_running()) {
        const int frame_start = SDL_GetTicks();

        game->update();
        game->draw();

        delta = SDL_GetTicks() - delta;
        if (FRAME_MS > delta) {
            SDL_Delay(FRAME_MS - delta);
        }
    }

    return 0;
}
