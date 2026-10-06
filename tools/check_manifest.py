#!/usr/bin/env python3
import json
from pathlib import Path

root = Path(__file__).resolve().parents[1]
manifest = root / "evidence" / "manifests" / "NT-PYTH-001.json"
data = json.loads(manifest.read_text(encoding="utf-8"))
required = ["context_id", "lean", "cpp", "ffi", "provenance"]
missing = [key for key in required if key not in data]
if missing:
    raise SystemExit(f"missing manifest keys: {missing}")
if data["context_id"] != "NT-PYTH-001":
    raise SystemExit("unexpected context id")
print("manifest ok")
