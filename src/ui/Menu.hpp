#pragma once

namespace hellms {

class Menu {
public:
    Menu() = default;
    ~Menu() = default;

    bool init();
    void render();
    int handle_event(int event);
    // Menu state
    enum class State { MAIN, PAUSE, SETTINGS };
    State state() const { return state_; }
    void set_state(State s) { state_ = s; }

private:
    State state_ = State::MAIN;
    // Button states
    bool new_game_ = false;
    bool settings_ = false;
    bool exit_ = false;
};
} // namespace hellms