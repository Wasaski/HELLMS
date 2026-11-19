#pragma once

namespace hellms {

class Tree {
public:
    Tree() = default;
    ~Tree() = default;

    bool init();
    void update(float delta);
    void render() const;
private:
    float height_ = 2.0f;
    float width_ = 0.3f;
};
} // namespace hellms