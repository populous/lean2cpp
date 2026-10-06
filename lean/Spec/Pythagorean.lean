import Mathlib

namespace Diophantine

/-- A concrete Pythagorean triple. -/
def isPythagorean (x y z : Nat) : Bool :=
  x ^ 2 + y ^ 2 == z ^ 2

example : isPythagorean 3 4 5 = true := by decide
example : isPythagorean 5 12 13 = true := by decide

end Diophantine
