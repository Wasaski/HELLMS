#include "Menu.hpp"
#include <cstdio>

namespace hellms {

bool Menu::init() {
    std::printf("Menu: Initializing main menu...\n");
    std::printf("Menu: Buttons - NEW GAME, CONTINUE (disabled), SETTINGS, EXIT\n");
    return true;
}

void Menu::render() {
    switch (state_) {
        case Menu::State::MAIN:
            std::printf("Menu: Rendering main menu\n");
            std::printf("  HELLMS\n");
            std::printf("  A place that shouldn't exist.\n");
            std::printf("  [NEW GAME]\n");
            std::printf("  [CONTINUE - disabled]\n");
            std::printf("  [SETTINGS]\n");
            std::printf("  [EXIT]\n");
            break;
        case Menu::State::PAUSE:
            std::printf("Menu: Rendering pause menu\n");
            std::printf("  [RESUME]\n");
            std::printf("  [SETTINGS]\n");
            std::printf("  [MAIN MENU]\n");
            break;
        case Menu::State::SETTINGS:
            std::printf("Menu: Rendering settings\n");
            std::printf("  Volume: [=====    ]\n");
            std::printf("  Camera sensitivity: [=====  ]\n");
            std::printf("  Graphics quality: [High    ]\n");
            std::printf("  [BACK]\n");
            break;
    }
}

int Menu::handle_event(int event) {
    (void)event;
    return 0;
}

} // namespace hellms