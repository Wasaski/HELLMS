#include "AudioManager.hpp"
#include <cstdio>

namespace hellms {

bool AudioManager::init() {
    std::printf("AudioManager: Initializing audio subsystem...\n");
    // Initialize OpenAL or SDL2 audio
    std::printf("AudioManager: Audio subsystem initialized.\n");
    return true;
}

void AudioManager::play_sound(const char* sound_name) {
    if (sound_name) {
        std::printf("AudioManager: Playing sound - %s\n", sound_name);
    }
}

void AudioManager::set_volume(float volume) {
    // Clamp to 0.0 - 1.0
    if (volume < 0.0f) volume = 0.0f;
    if (volume > 1.0f) volume = 1.0f;
    volume_ = volume;
    std::printf("AudioManager: Volume set to %.2f\n", volume_);
}

float AudioManager::volume() const {
    return volume_;
}

// Convenience functions for specific sounds
void AudioManager::play_wind() {
    play_sound("wind");
}

void AudioManager::play_forest_noise() {
    play_sound("forest_noise");
}

void AudioManager::play_step() {
    play_sound("step");
}

void AudioManager::play_door_open() {
    play_sound("door_open");
}

void AudioManager::play_door_close() {
    play_sound("door_close");
}
} // namespace hellms