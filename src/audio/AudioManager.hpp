#pragma once

namespace hellms {

class AudioManager {
public:
    AudioManager() = default;
    ~AudioManager() = default;

    bool init();
    void play_sound(const char* sound_name);
    void set_volume(float volume);
    float volume() const;

    // Convenience functions for specific sounds
    void play_wind();
    void play_forest_noise();
    void play_step();
    void play_door_open();
    void play_door_close();

private:
    float volume_ = 1.0f;
};
} // namespace hellms