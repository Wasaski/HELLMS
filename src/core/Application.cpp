#include "Application.hpp"
#include "Game.hpp"
#include <cstdio>

namespace hellms {

int Application::run(int argc, char** argv) {
    (void)argc;
    (void)argv;

    std::printf("Application starting...\n");

    if (!init()) {
        std::printf("Application initialization failed.\n");
        return 1;
    }

    game_.init();
    game_.run();

    std::printf("Application exiting.\n");
    return 0;
}

bool Application::init() {
    std::printf("Application initializing subsystems...\n");
    // Initialize subsystems here
    std::printf("Application subsystems initialized.\n");
    return true;
}

} // namespace hellms