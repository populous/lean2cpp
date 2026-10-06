#pragma once

#include <concepts>
#include <cstddef>
#include <cstdint>
#include <tuple>

namespace diophantine {

struct PythagoreanTriple {
    std::uint64_t x;
    std::uint64_t y;
    std::uint64_t z;
};

template <typename T>
concept PythagoreanWitness = requires(const T& value) {
    { value.x } -> std::convertible_to<std::uint64_t>;
    { value.y } -> std::convertible_to<std::uint64_t>;
    { value.z } -> std::convertible_to<std::uint64_t>;
};

constexpr bool is_pythagorean(std::uint64_t x,
                              std::uint64_t y,
                              std::uint64_t z) noexcept {
    return x * x + y * y == z * z;
}

constexpr PythagoreanTriple euclidean_triple(
    std::uint64_t m,
    std::uint64_t n
) noexcept {
    return {
        m * m - n * n,
        2 * m * n,
        m * m + n * n
    };
}

constexpr bool valid_euclidean_triple(
    std::uint64_t m,
    std::uint64_t n
) noexcept {
    if (n > m) {
        return false;
    }
    const auto result = euclidean_triple(m, n);
    return is_pythagorean(result.x, result.y, result.z);
}

static_assert(valid_euclidean_triple(2, 1));
static_assert(valid_euclidean_triple(3, 2));
static_assert(valid_euclidean_triple(4, 1));

} // namespace diophantine
