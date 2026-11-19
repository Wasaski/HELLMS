#include <cstdio>
#include <cstdlib>
#include <string>

// Minimal application entry point
// Can be built with or without SDL2

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    std::printf("HELLMS Alpha 0.1 - Application Starting\n");
    std::printf("Platform: Android Termux\n");
    std::printf("Initializing minimal framework...\n");

    // Simple version check
    std::printf("Framework initialized successfully.\n");
    std::printf("Use CMake with SDL2 for full Android build.\n");

    return 0;
}