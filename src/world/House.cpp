#include "House.hpp"
#include <cstdio>

namespace hellms {

bool House::init() {
    std::printf("House: Initializing geometry...\n");
    // Floor
    std::printf("House: Floor created.\n");
    // Walls
    std::printf("House: Walls created.\n");
    // Ceiling
    std::printf("House: Ceiling created.\n");
    // Main door
    std::printf("House: Main door created.\n");
    // Window
    std::printf("House: Window created.\n");
    // Table
    std::printf("House: Table created.\n");
    // Bed
    std::printf("House: Bed created.\n");
    // Chair
    std::printf("House: Chair created.\n");
    std::printf("House: Geometry initialization complete.\n");
    return true;
}

void House::update(float delta) {
    // Update house state
    (void)delta;
}

void House::render() {
    std::printf("House: Rendering scene.\n");
}

} // namespace hellms