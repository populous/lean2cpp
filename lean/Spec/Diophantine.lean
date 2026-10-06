import Mathlib

namespace Diophantine

/-- A natural-number Pythagorean relation. -/
def Pythagorean (x y z : Nat) : Prop :=
  x ^ 2 + y ^ 2 = z ^ 2

/-- A Diophantine witness for the Pythagorean equation. -/
structure PythagoreanWitness where
  x : Nat
  y : Nat
  z : Nat
  equation : Pythagorean x y z

/-- Given two legs and a square-witness for their sum, return the verified hypotenuse relation. -/
theorem pythagorean_from_legs
    (x y z : Nat)
    (h : x ^ 2 + y ^ 2 = z ^ 2) :
    Pythagorean x y z := by
  exact h

/-- The standard Euclidean parameter construction. -/
def pythagoreanTriple (m n : Nat) : Nat × Nat × Nat :=
  (m ^ 2 - n ^ 2, 2 * m * n, m ^ 2 + n ^ 2)

/-- The Euclidean construction satisfies the Pythagorean equation when n ≤ m.

The subtraction side condition is explicit because Nat subtraction is truncated.
-/
theorem pythagorean_triple_is_valid
    (m n : Nat)
    (h : n ≤ m) :
    Pythagorean
      (m ^ 2 - n ^ 2)
      (2 * m * n)
      (m ^ 2 + n ^ 2) := by
  dsimp [Pythagorean]
  nlinarith [Nat.sub_add_cancel (Nat.pow_le_pow_left h 2)]

/-- A witness packaged as a dependent result. -/
def euclideanWitness (m n : Nat) (h : n ≤ m) :
    PythagoreanWitness := by
  refine ⟨m ^ 2 - n ^ 2, 2 * m * n, m ^ 2 + n ^ 2, ?_⟩
  exact pythagorean_triple_is_valid m n h

end Diophantine
