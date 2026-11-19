#include "World.hpp"
#include <cstdio>

namespace hellms {

bool World::init() {
    std::printf("World initializing...\n");
    if (!house_.init()) {
        std::printf("Failed to initialize house.\n");
        return false;
    }
    if (!forest_.init()) {
        std::printf("Failed to initialize forest.\n");
        return false;
    }
    std::printf("World initialized.\n");
    return true;
}

void World::update(float delta) {
    house_.update(delta);
    forest_.update(delta);
}

void World::render() {
    house_.render();
    forest_.render();
}
} // namespace hellms