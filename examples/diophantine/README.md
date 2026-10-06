# Diophantine Pythagorean Example

Context ID: `NT-PYTH-001`

This example connects the Pythagorean equation with a Diophantine predicate.
It demonstrates the two-backend protocol:

- Lean defines the mathematical predicate and proves the two-leg-to-hypotenuse construction.
- C++ provides a constexpr/native implementation and runtime tests.

## Mathematical context

For natural numbers `m` and `n` with `n ≤ m`, define:

```text
x = m² - n²
y = 2mn
z = m² + n²
```

Then:

```text
x² + y² = z²
```

The proof is an algebraic identity. It is a Diophantine witness because all values are natural numbers.

## Lean

The Lean module is `Diophantine.Pythagorean`.

The main theorem is:

```lean
pythagorean_from_legs
```

It takes two natural-number legs `x` and `y`, assumes that `x² + y²` is a perfect square through a witness `z`, and returns the verified hypotenuse relation.

It also includes the Euclidean-style parameter construction:

```lean
pythagoreanTriple
pythagorean_triple_is_valid
```

## C++

`cpp/diophantine/pythagorean.hpp` contains:

- a structural `PythagoreanWitness` concept;
- `constexpr` verification;
- the Euclidean parameter construction;
- a result type for the two-legs-to-hypotenuse operation.

## Protocol gates

```text
context-id-check
lean-definition-check
lean-theorem-check
cpp-concept-check
cpp-build-check
representative-test
manifest-generation
```

The C++ tests are executable evidence. They do not replace the Lean theorem.
