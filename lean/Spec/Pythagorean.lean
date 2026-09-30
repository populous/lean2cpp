namespace Lean2Cpp

/-- The Pythagorean relation over natural numbers. -/
def Pythagorean (a b c : Nat) : Prop :=
  a * a + b * b = c * c

/-- The canonical 3-4-5 Pythagorean triple. -/
theorem three_four_five : Pythagorean 3 4 5 := by
  norm_num [Pythagorean]

/-- Symmetry of the two legs. -/
theorem pythagorean_commutative (a b c : Nat) :
    Pythagorean a b c → Pythagorean b a c := by
  intro h
  simpa [Pythagorean, Nat.add_comm] using h

/-- A direct specification theorem: a supplied equality is the relation. -/
theorem relation_holds_of_equality
    (a b c : Nat)
    (h : a * a + b * b = c * c) :
    Pythagorean a b c := by
  exact h

end Lean2Cpp
