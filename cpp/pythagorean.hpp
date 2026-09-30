#pragma once

#include <cstdint>

namespace lean2cpp {

[[nodiscard]] bool is_pythagorean(
    std::int64_t a,
    std::int64_t b,
    std::int64_t c);

}  // namespace lean2cpp
