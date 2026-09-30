# Lean2Cpp

Lean specification, C++ implementation, and Python boundary example.

## Goal

This repository demonstrates a three-layer workflow:

- Lean: executable specification and theorem proof.
- C++: high-performance implementation with explicit precondition checks.
- Python: validated application boundary.

The Pythagorean theorem example states that for natural numbers `a`, `b`, and `c`, if `a^2 + b^2 = c^2`, then the corresponding right-triangle relation holds. The C++ example computes and checks the same relation; it is a companion implementation, not automatically proven equivalent to the Lean code.

## Layout

```text
lean/Spec/Pythagorean.lean  Lean specification and proofs
cpp/                        C++20 implementation
python/                     Python validation boundary
tests/                      Python tests
```

## Lean

With Lean 4 and Lake installed:

```bash
lake build
```

## C++

```bash
c++ -std=c++20 -Wall -Wextra -Werror -pedantic \\
  cpp/pythagorean.cpp -Icpp -o pythagorean_demo
./pythagorean_demo
```

## Python

```bash
python -m pytest -q
```

## Assurance boundary

The Lean theorem is checked by the Lean kernel. The C++ implementation is separately tested and contains runtime checks. Establishing formal equivalence between the C++ implementation and the Lean specification requires an additional refinement proof or a verified extraction/backend.
