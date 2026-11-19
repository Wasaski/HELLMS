#pragma once

namespace hellms {

class Player {
public:
    Player() = default;
    ~Player() = default;

    bool init();
    void update(float delta);
    void render();
    // Position/rotation accessors
    float* position() { return position_; }
    float* rotation() { return rotation_; }

private:
    float position_[3] = {0.0f, 0.0f, 0.0f};
    float rotation_[2] = {0.0f, 0.0f}; // pitch, yaw
};
} // namespace hellms