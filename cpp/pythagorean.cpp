#include "pythagorean.hpp"

#include <limits>

namespace lean2cpp {
namespace {

[[nodiscard]] bool square_fits(std::int64_t value) noexcept {
    if (value < 0) {
        return false;
    }
    return value == 0 || value <=
        std::numeric_limits<std::int64_t>::max() / value;
}

}  // namespace

bool is_pythagorean(
    std::int64_t a,
    std::int64_t b,
    std::int64_t c) {
    if (!square_fits(a) || !square_fits(b) || !square_fits(c)) {
        return false;
    }

    const auto aa = a * a;
    const auto bb = b * b;
    const auto cc = c * c;

    if (aa > std::numeric_limits<std::int64_t>::max() - bb) {
        return false;
    }

    return aa + bb == cc;
}

}  // namespace lean2cpp

#ifdef LEAN2CPP_DEMO
#include <iostream>

int main() {
    std::cout << std::boolalpha
              << lean2cpp::is_pythagorean(3, 4, 5) << '\\n';
}
#endif
