#!/usr/bin/env bash
# Build KKND.EXE from src/ and verify it byte-for-byte against the retail executable.
#
# Usage: tools/build-and-verify.sh [-v]
#   -v  print instruction diffs for any C function that does not match
#
# Success = "build/DOS/KKND.EXE: OK" and exit code 0. Anything else is a build failure:
# a non-matching C function, a relocation that resolves to a different target, or a SHA-1
# mismatch. Treat it as failed; never commit on red.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"
PYTHON=python3
for cand in venv/Scripts/python.exe venv/bin/python3 .venv/bin/python3; do
    if [[ -x "$cand" ]]; then PYTHON="$cand"; break; fi
done
# python3 on Windows can be the Microsoft Store stub: fall back to python if it cannot run.
"$PYTHON" -c "" >/dev/null 2>&1 || PYTHON=python
if "$PYTHON" tools/build_kknd.py "$@"; then
    "$PYTHON" tools/make_report.py >/dev/null
    echo "✅ BUILD SUCCEEDED. Everything matched."
else
    echo "BUILD HAS FAILED. Treat this as a build failure: a non-matching function or checksum is never acceptable."
    exit 1
fi
