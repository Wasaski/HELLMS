#include "Tree.hpp"
#include <cstdio>
#include <cstdlib>

namespace hellms {

bool Tree::init() {
    // Random height and width variations using rand()
    height_ = 2.0f + static_cast<float>(rand()) / RAND_MAX * 3.0f; // 2-5 units
    width_ = 0.3f + static_cast<float>(rand()) / RAND_MAX * 0.4f;  // 0.3-0.7 units
    
    std::printf("Tree: Initialized - height: %.2f, width: %.2f\n", height_, width_);
    return true;
}

void Tree::update(float delta) {
    (void)delta;
}

void Tree::render() const {
    std::printf("Tree: Rendering (height: %.2f, width: %.2f)\n", height_, width_);
    // Would render trunk + canopy using OpenGL ES 3.0
}
} // namespace hellms