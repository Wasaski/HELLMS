#pragma once

#include <vector>

namespace hellms {

class Tree;

class Forest {
public:
    Forest();
    ~Forest();

    bool init();
    void update(float delta);
    void render();

private:
    int tree_count_ = 0;
    std::vector<Tree> trees_;
};
} // namespace hellms