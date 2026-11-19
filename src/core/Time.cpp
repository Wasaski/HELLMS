#include "Time.hpp"
#include <chrono>

namespace hellms {

void Time::reset() {
    start_ = get_current_time();
    elapsed_ = 0.0;
}

double Time::delta() const {
    return elapsed_;
}

void Time::tick() {
    auto now = get_current_time();
    elapsed_ = now - start_;
    start_ = now;
}

double Time::get_current_time() {
    auto now = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
    return static_cast<double>(ms.count()) / 1000.0f;
}

} // namespace hellms