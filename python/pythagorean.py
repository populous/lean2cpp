from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True, slots=True)
class NaturalNumber:
    value: int

    def __post_init__(self) -> None:
        if self.value < 0:
            raise ValueError("natural numbers must be non-negative")


def is_pythagorean(a: int, b: int, c: int) -> bool:
    values = tuple(NaturalNumber(x).value for x in (a, b, c))
    left_a, left_b, right_c = values
    return left_a * left_a + left_b * left_b == right_c * right_c
