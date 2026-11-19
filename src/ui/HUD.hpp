#pragma once

namespace hellms {

class HUD {
public:
    HUD() = default;
    ~HUD() = default;

    void render();
    void set_interaction_text(const char* text);
    void set_mouse_visible(bool visible);
private:
    bool interaction_visible_ = false;
    char interaction_text_[256] = {0};
};
} // namespace hellms