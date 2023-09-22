#include "SDL2/SDL_timer.h"
#include "game.h"
#include <memory>

int main() {
    auto game = std::make_unique<Game>();

    while (game->is_running()) {
        const int frame_start = SDL_GetTicks();

        game->update();
        game->draw();

        const int frame_duration_ms = SDL_GetTicks() - frame_duration_ms;
        if (FRAME_MS > frame_duration_ms) {
            SDL_Delay(FRAME_MS - frame_duration_ms);
        }
    }

    return 0;
}
