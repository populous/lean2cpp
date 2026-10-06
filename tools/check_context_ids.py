#!/usr/bin/env python3
from pathlib import Path

root = Path(__file__).resolve().parents[1]
context_ids = []
for path in root.glob("context/**/*.yaml"):
    text = path.read_text(encoding="utf-8")
    for line in text.splitlines():
        if line.startswith("id:"):
            context_ids.append(line.split(":", 1)[1].strip())

if len(context_ids) != len(set(context_ids)):
    raise SystemExit("duplicate context id")
if "NT-PYTH-001" not in context_ids:
    raise SystemExit("NT-PYTH-001 missing")
print(f"context ids ok: {len(context_ids)}")
