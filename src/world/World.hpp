#pragma once

#include "House.hpp"
#include "Forest.hpp"

namespace hellms {

class World {
public:
    World() = default;
    ~World() = default;

    bool init();
    void update(float delta);
    void render();

private:
    House house_;
    Forest forest_;
};
} // namespace hellms