#pragma once

namespace hellms {

class PauseMenu {
public:
    PauseMenu() = default;
    ~PauseMenu() = default;

    bool init();
    void render();
    int handle_event(int event);
    bool is_paused() const { return paused_; }
    void set_paused(bool p) { paused_ = p; }

private:
    bool paused_ = false;
};
} // namespace hellms