#pragma once

namespace hellms {

class Game {
public:
    Game() = default;
    ~Game() = default;

    bool init();
    void run();
    void stop();
};
} // namespace hellms