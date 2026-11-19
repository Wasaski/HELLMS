#include "Player.hpp"
#include <cstdio>

namespace hellms {

bool Player::init() {
    std::printf("Player: Initialized at origin.\n");
    position_[1] = 1.6f; // Eye level
    return true;
}

void Player::update(float delta) {
    // Update player state - movement, etc.
    (void)delta;
}

void Player::render() {
    // Render player camera
}

} // namespace hellms