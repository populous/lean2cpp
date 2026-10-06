#include "diophantine/pythagorean.hpp"

#include <cassert>

int main() {
    using namespace diophantine;

    static_assert(PythagoreanWitness<PythagoreanTriple>);

    const auto triple = euclidean_triple(2, 1);
    assert(triple.x == 3);
    assert(triple.y == 4);
    assert(triple.z == 5);
    assert(is_pythagorean(triple.x, triple.y, triple.z));

    const auto triple_13 = euclidean_triple(3, 2);
    assert(triple_13.x == 5);
    assert(triple_13.y == 12);
    assert(triple_13.z == 13);
    assert(is_pythagorean(triple_13.x, triple_13.y, triple_13.z));

    assert(!valid_euclidean_triple(1, 2));
    return 0;
}
