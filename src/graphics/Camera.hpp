#pragma once

namespace hellms {

class Camera {
public:
    Camera();
    ~Camera();

    void update(float delta);

    // First-person camera controls
    void set_position(float x, float y, float z);
    void set_rotation(float pitch, float yaw);

    // Get view matrix
    float* view_matrix();

    // Get projection matrix
    float* projection_matrix();

private:
    float position_[3] = {0.0f, 0.0f, 0.0f};
    float pitch_ = 0.0f;
    float yaw_ = 0.0f;
    float view_matrix_[16];
    float projection_matrix_[16];
};
} // namespace hellms