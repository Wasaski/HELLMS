#pragma once

namespace hellms {

class Controller {
public:
    Controller() = default;
    ~Controller() = default;

    void handle_input(float delta, bool forward, bool backward, bool left, bool right,
                      bool look_up, bool look_down, bool interact, bool pause);
    void set_dead_zone(float dz) { dead_zone_ = dz; }
    void set_sensitivity(float sens) { sensitivity_ = sens; }

    // Input state accessors
    bool is_moving_forward() const { return move_forward_; }
    bool is_moving_backward() const { return move_backward_; }
    bool is_moving_left() const { return move_left_; }
    bool is_moving_right() const { return move_right_; }
    bool is_interacting() const { return interact_; }
    bool is_paused() const { return paused_; }

    // Configuration accessors
    float dead_zone() const { return dead_zone_; }
    float sensitivity() const { return sensitivity_; }

private:
    float dead_zone_ = 0.1f;
    float sensitivity_ = 1.0f;
    float delta_ = 0.0f;
    
    // Input state
    bool move_forward_ = false;
    bool move_backward_ = false;
    bool move_left_ = false;
    bool move_right_ = false;
    bool interact_ = false;
    bool paused_ = false;
};
} // namespace hellms