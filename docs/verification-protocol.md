# Lean + C++ Verification Protocol

This repository separates mathematical verification from native implementation verification.

## Gates

1. Context ID validation.
2. Lean specification build.
3. C++ compile and test.
4. Manifest schema validation.

## NT-PYTH-001

`NT-PYTH-001` connects the Diophantine Pythagorean relation
`x^2 + y^2 = z^2` with:

- Lean predicate and Euclidean construction theorem.
- C++ concept, `constexpr` implementation, and representative tests.

C++ executable evidence does not replace the Lean theorem. The manifest records this distinction.
