#include "Game.hpp"
#include <cstdio>

namespace hellms {

bool Game::init() {
    std::printf("Game: Initializing...\n");
    return true;
}

void Game::run() {
    std::printf("Game: Running main loop...\n");
    // Main game loop would go here
}
} // namespace hellms