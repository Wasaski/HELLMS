#include "Forest.hpp"
#include "Tree.hpp"
#include <cstdio>

namespace hellms {

Forest::Forest() {
    tree_count_ = 0;
}

Forest::~Forest() {
}

bool Forest::init() {
    std::printf("Forest: Initializing with procedural trees...\n");
    
    // Create tree instances using instancing
    // Tree count for a "sufficiently large forest"
    constexpr int kTreeCount = 50;
    
    trees_.resize(kTreeCount);
    
    for (int i = 0; i < kTreeCount; i++) {
        if (!trees_[i].init()) {
            std::printf("Forest: Failed to initialize tree %d\n", i);
        } else {
            tree_count_++;
        }
    }
    
    std::printf("Forest: %d trees initialized.\n", tree_count_);
    return tree_count_ > 0;
}

void Forest::update(float delta) {
    (void)delta;
    for (auto& tree : trees_) {
        tree.update(delta);
    }
}

void Forest::render() {
    for (const auto& tree : trees_) {
        tree.render();
    }
}
} // namespace hellms