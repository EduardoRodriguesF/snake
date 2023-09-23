#include "utils.h"

bool operator==(SDL_Point lfs, SDL_Point rhs) {
    return lfs.x == rhs.x && lfs.y == rhs.y;
}
