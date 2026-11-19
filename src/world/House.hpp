#pragma once

namespace hellms {

class House {
public:
    House() = default;
    ~House() = default;

    bool init();
    void update(float delta);
    void render();
};
} // namespace hellms