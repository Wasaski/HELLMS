#pragma once

namespace hellms {

class Time {
public:
    Time() = default;
    ~Time() = default;

    void reset();
    double delta() const;
    void tick();

private:
    static double get_current_time();

    double start_ = 0.0;
    double elapsed_ = 0.0;
};
} // namespace hellms