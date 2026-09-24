# KKND Decompilation

<!-- PROGRESS:BADGE -->
![matched](https://img.shields.io/badge/matched-484%2F3713%20(13.04%25)-1f6feb)
<!-- /PROGRESS:BADGE -->
![build](https://img.shields.io/badge/build-byte--identical-2ea043)
![platform](https://img.shields.io/badge/platform-DOS%20(Watcom%20C%20%2B%20DOS%2F4GW)-8957e5)

A work-in-progress **matching decompilation** of *KKND: Krush Kill 'n Destroy*
(Beam Software / Melbourne House, 1997) for MS-DOS.

The goal is to recover readable C that, when compiled with a period-correct Watcom
toolchain, produces a binary **byte-identical** to the original executable, then a moddable
full-source tree.

| Item | Value |
|---|---|
| Platform | MS-DOS, 32-bit protected mode (DOS/4GW Professional, bound) |
| Target | `KKND.EXE` (retail CD, build date `Feb 16 1997`) |
| Exe SHA-1 | `024e96860c504b462b24b9237d49bfe8de6eb8e0` (1,062,709 bytes) |
| Format | MZ stub + DOS/4GW Pro + Linear Executable (LE), 3 objects, 20,192 fixups |
| Compiler | Watcom C/C++32 (1994 runtime, Watcom 10.x) — matched with Open Watcom `wcc386` |
| Flags | `-s -of+ -5r -omiler -zm -zp1` (see `COMPILER_ANALYSIS.md`) |
| Language | C (48 game modules named by their own `__FILE__` strings) |
| Structure | single LE executable, no overlays |
| License (project code) | CC0 1.0 |

> **You must own the game.** This repository contains no executables, levels, sprites, sounds,
> FMV or any other copyrighted asset. Everything under `dumps/ asm/ build/` is regenerated from
> *your own* KKND CD and is gitignored.

## Status

Phase 0 is complete: the LE image is split per function and relinks **byte-identical** to the
retail executable, and C functions are spliced in and verified individually. Each matched
function is verified by the full rebuild still producing `build/DOS/KKND.EXE: OK` (SHA-1 match)
with every relocation resolving to the original target — a scratch match alone is never enough.

### Progress by component

<!-- PROGRESS:TABLE -->
| Component | Functions | Matched | Progress |
|---|---:|---:|---|
| **Main executable** (`KKND.EXE`) | 3713 | 484 | `▰▰▰▱▱▱▱▱▱▱▱▱▱▱▱▱▱▱▱▱` 13.04% |
| &nbsp;&nbsp;└ Game code (`src/*.c`, 48 modules) | 2006 | 481 | `▰▰▰▰▰▱▱▱▱▱▱▱▱▱▱▱▱▱▱▱` 23.98% |
| &nbsp;&nbsp;└ Libraries (`src/lib/`) | 1707 | 3 | `▱▱▱▱▱▱▱▱▱▱▱▱▱▱▱▱▱▱▱▱` 0.18% |
<!-- /PROGRESS:TABLE -->

Game code is the 48 C modules Beam Software wrote (`main.c`, `units.c`, `mission.c`,
`enemyai.c`, …). Libraries are the statically linked Watcom C runtime, StratosWare MemCheck 3.5,
SciTech UniVBE / VBE-AF and the HMI SOS sound driver loader.

## Layout

| Path | What |
|------|------|
| `src/*.c` | decompiled C, one file per original game module (`src/lib/` for libraries) |
| `include/` | headers |
| `configs/DOS/` | function list, unit map, symbol names, compiler flags, target SHA-1 |
| `asm/DOS/nonmatchings/` | per-function disassembly (generated, gitignored) |
| `tools/` | LE/OMF readers, splitter, build + verify, matcher, report, progress |
| `PLAN.md` / `PROGRESS.md` | roadmap and progress tracker |
| `DECOMPILATION_LEARNINGS.md` | the matching journal |
| `KKND_NOTES.md` | findings about the executable, formats and engine |

## Quick start

Copy your KKND CD to `dumps/disc/` (so that `dumps/disc/KKND/KKND.EXE` exists). Install
[Open Watcom](https://github.com/open-watcom/open-watcom-1.9/releases) 1.9 (or 2.0) and point
`WATCOM` at it. Then:

```
python -m venv venv                        # venv\Scripts on Windows
pip install -r requirements.txt
python tools/find_functions.py             # -> configs/DOS/functions.csv (committed)
python tools/split.py                      # -> asm/DOS/nonmatchings/*.s
python tools/build_kknd.py                 # expect: build/DOS/KKND.EXE: OK
```

`tools/build_kknd.py` compiles `src/**/*.c` with `wcc386`, cuts every C function out of its
OMF object, requires it to be byte-identical to the original (relocations masked but their
*targets* checked), splices it into the LE image, rewrites the executable and checks the SHA-1.

## Contributing a match

1. `python tools/score_functions.py` ranks the easiest unmatched functions.
2. Read `asm/DOS/nonmatchings/<func>.s`, write C in a scratch file and iterate with
   `python tools/match.py scratch.c` until it prints `OK`.
3. Replace the function's `INCLUDE_ASM` in its `src/<module>.c` with the C. Prefer proper
   structs over pointer arithmetic.
4. Verify with `python tools/build_kknd.py`. Only `build/DOS/KKND.EXE: OK` counts as done.
5. `python tools/update_readme_progress.py --sync`, then commit. One matched function is one commit.

## Credits

KKND was developed by Beam Software and released in 1997 under the Melbourne House label. This project is an unofficial fan effort, not affiliated with or
endorsed by the rights holders, and is intended to preserve and study the game.
Workflow and project structure follow the Digimon World 2 decomp. KKND data-format notes
build on OpenKrush by IceReaper.
