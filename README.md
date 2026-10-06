# lean2cpp

Lean specifications, verified reference implementations, generated C++ adapters, and Python bindings.

## Verification example

The repository contains a Diophantine/Pythagorean example under context ID `NT-PYTH-001`.

```bash
# Lean
lake build

# C++ representative test
g++ -std=c++20 -Wall -Wextra -Werror \
  -Icpp/diophantine \
  tests/diophantine/pythagorean_test.cpp \
  -o pythagorean_test
./pythagorean_test

# Protocol checks
python3 tools/check_context_ids.py
python3 tools/check_manifest.py
```

See `docs/verification-protocol.md` for the Lean/C++ verification boundary.
