#include "Controller.hpp"
#include <cstdio>

namespace hellms {

void Controller::handle_input(float delta, bool forward, bool backward, bool left, bool right,
                              bool look_up, bool look_down, bool interact, bool pause) {
    delta_ = delta;
    sensitivity_ = 1.0f;
    dead_zone_ = 0.1f;

    // Map input to movement state
    move_forward_ = forward;
    move_backward_ = backward;
    move_left_ = left;
    move_right_ = right;
    interact_ = interact;
    paused_ = pause;

    // Simple input processing
    if (forward) std::printf("Controller: Forward input\n");
    if (backward) std::printf("Controller: Backward input\n");
    if (left) std::printf("Controller: Left input\n");
    if (right) std::printf("Controller: Right input\n");
    if (interact) std::printf("Controller: Interact input\n");
    if (pause) std::printf("Controller: Pause input\n");
}
} // namespace hellms