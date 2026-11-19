#include "PauseMenu.hpp"
#include <cstdio>

namespace hellms {

bool PauseMenu::init() {
    std::printf("Pause menu initialized.\n");
    return true;
}

void PauseMenu::render() {
    if (!paused_) return;
    std::printf("Pause menu:\n");
    std::printf("  [RESUME]\n");
    std::printf("  [SETTINGS]\n");
    std::printf("  [MAIN MENU]\n");
}

int PauseMenu::handle_event(int event) {
    (void)event;
    return 0;
}

} // namespace hellms