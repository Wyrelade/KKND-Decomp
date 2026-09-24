# KKND Decomp Progress Tracker

**1 function = 1 match = 1 commit.** Replace an `INCLUDE_ASM` with C, verify with
`python tools/build_kknd.py` (prints `build/DOS/KKND.EXE: OK`), commit, update this file.

> This `matched:` line is the single source of truth for progress. After a match, run
> `python tools/update_readme_progress.py --sync` (recounts from `src/`, rewrites these two
> lines, regenerates the README badge and progress table) and include both files in the commit.

**Main exe functions identified: 3713 · matched: 492 (13.25%)**  ·  updated 2026-09-24

**Game code: 489/2006 · Libraries: 3/1707**

## Phase 0 Bring-up

| done | step | note |
|---|------|------|
| [x] | disc copied | `dumps/disc/` (gitignored); `KKND.EXE` SHA-1 `024e9686…b8e0` |
| [x] | exe format | MZ + bound DOS/4GW Professional + LE at 0x28FEC (stub MZ 0x26654); 3 objects |
| [x] | LE reader | `tools/le.py`: object pages + all 20,192 fixups decoded, every OFF32 field verified |
| [x] | function discovery | `tools/find_functions.py`: 3713 functions, 96.6% of the code object decoded |
| [x] | per-function split | `tools/split.py` -> `asm/DOS/nonmatchings/*.s` (symbolic, reloc-aware) |
| [x] | compiler pinned | Watcom 10.x class; Open Watcom 1.9 `-s -of+ -5r -omiler -zm -zp1` matches (`COMPILER_ANALYSIS.md`) |
| [x] | OMF reader | `tools/omf.py`: segments, publics, LEDATA/LIDATA, FIXUPP (self-rel vs segment-rel) |
| [x] | build wiring | `tools/build_kknd.py`: compile, per-function verify (bytes + reloc targets), splice, SHA-1 |
| [x] | first green build | unmodified split rebuilds byte-identical (`build/DOS/KKND.EXE: OK`) |
| [x] | unit map | 48 game modules from `__FILE__` strings (`configs/DOS/units.csv`), `src/<module>.c` |
| [x] | first matches | func_000100C0, func_00012080, func_00012390 + 43 empty stub functions |
| [x] | decomp.dev report | `tools/make_report.py` + `.github/workflows/progress.yml` |
| [ ] | refine discovery | 3.4% of the code object undecoded (int-thunk tables, dead code); a few table false positives |
| [ ] | library labelling | Watcom clib / MemCheck / UniVBE / HMI signatures -> names |
| [ ] | data layout | object 3 (0xB0000, 228 KB) symbolised: strings, tables, BSS |
| [ ] | unit boundaries | exact start of every module (currently first anchor function, [H]) |

## Session log

### 2026-09-24 — kickoff

Project created from the DW2 / OpenWINGS templates. The retail CD's `KKND.EXE` is a Watcom C
program bound to DOS/4GW Professional. Built the whole pipeline from scratch (no splat /
objdiff support for LE/OMF): LE reader (the data-page offset is relative to the *stub* MZ at
0x26654, not the file start — first attempt read garbage pages), recursive-descent function
finder with switch-table following through fixups, per-function splitter, OMF reader, matcher
and the byte-identical build gate (splices verified C into the LE and SHA-1 checks it). Pinned
the compiler flags from 4 probe functions: `-of+` (frame on every function), `-s` (no stack
check), `-ox`, `-4r/-5r` (`and eax,0xff` zero-extension), `-zm` (one segment per function =
the 16-byte zero padding between functions, and no cross-function tail merging). 3 matched by
hand, then the 43 empty `void f(void) {}` stubs (compiled-out debug hooks) as one family: 46.
Open: Watcom 10.x vs Open Watcom loop layout (func_000121B0, see `tools/difficult_functions`).

### 2026-09-24 — kickoff, part 2 (97 -> 327)

Flags `-omiler` (no `-ob`) and `-zp1`; switch tables verified and spliced by the build (Watcom puts
the table at the start of the function's own segment). Four parallel agents matched by module
group (A units, B engine, C network/UI, D gameplay); their notes are in `doc/agent_notes/`, to be
merged into the journal. Known blockers: Open Watcom jump threading / loop layout (`jt`) and the
missing `cs:` prefix on switch jumps (patched compiler in progress, PLAN 1.7).

### 2026-09-24 — session 2 (327 -> 492)

Merged the agent notes (and made `-ot` global), then made the patched Open Watcom `wcc386` the
default toolchain (`doc/compiler_patch.md`): switch jump tables via `cs:`, Watcom 10 switch costs
and pure binary search, no loop/table padding, no loop-entry jump threading, bottom-test loop
entry, EBX before ECX, shift/add constant multiplies. func_000121B0, func_00053700 (`jt`),
func_000323B0, func_0001CDC4 (switch) and the `rp` probe func_0002E940 now match as plain C.
Applied 55 real names from `name_evidence.csv`. Four agents then two second-pass agents matched
by module group. Matched **327 -> 492** (+165), build `OK`. Short of the +250 target: the
remaining functions are dominated by `ci` and `fold` compiler differences (next patches).

