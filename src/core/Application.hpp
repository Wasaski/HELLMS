#pragma once

#include "Game.hpp"

namespace hellms {

class Application {
public:
    Application() = default;
    ~Application() = default;

    int run(int argc, char** argv);

private:
    bool init();
    Game game_;
};
} // namespace hellms