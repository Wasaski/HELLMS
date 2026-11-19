#include "HUD.hpp"
#include <cstdio>

namespace hellms {

void HUD::render() {
    // Render minimal HUD
    std::printf("HUD: Rendering minimal interface...\n");
    
    // Central crosshair
    std::printf("  [CROSSHAIR]\n");
    
    // Interaction indicator
    if (interaction_visible_) {
        std::printf("  [INTERACT] %s\n", interaction_text_);
    }
    
    // Joystick indicator
    std::printf("  [JOYSTICK]\n");
    
    // Pause button indicator
    std::printf("  [PAUSE]\n");
}

void HUD::set_interaction_text(const char* text) {
    if (text) {
        snprintf(interaction_text_, sizeof(interaction_text_), "%s", text);
        interaction_visible_ = true;
    } else {
        interaction_visible_ = false;
    }
}

void HUD::set_mouse_visible(bool visible) {
    (void)visible;
}

} // namespace hellms