# KKND — Decomp → Full Source Project Plan

**Goal:** replace **every** `INCLUDE_ASM` stub with matching C, reach a 100% decompiled source
tree for `KKND.EXE` that still rebuilds byte-identical to the retail executable, then a
readable, moddable, portable source tree.

**Target:** `KKND.EXE` from the retail CD (Beam Software, build date `Feb 16 1997`,
SHA-1 `024e96860c504b462b24b9237d49bfe8de6eb8e0`).

**Success gate (every step):** `python tools/build_kknd.py` prints `build/DOS/KKND.EXE: OK`.
If it doesn't, the change is not done.

**Team:** solo (Wyrelade).

**Evidence tags** (as in the OpenWINGS plan): **[C]** confirmed by bytes / disassembly / a
matching build, **[H]** hypothesis, **[?]** unknown. Only [C] goes into code comments as fact.

---

## ▶ PHASE 0 — Bring-up (get to a first green build)  [DONE 2026-09-24]

There is no splat/objdiff for Watcom LE executables, so Phase 0 built the equivalents.

| # | Step | Notes | Done |
|---|------|-------|:---:|
| 0.1 | Copy disc | `dumps/disc/` from the CD image. `KKND.EXE` SHA-1 recorded in `configs/DOS/KKND.EXE.sha1`. | done |
| 0.2 | Exe format | MZ stub + bound DOS/4GW Pro + LE (header 0x28FEC, owning stub MZ 0x26654). `tools/le.py`. | done |
| 0.3 | Fixups | 20,192 LE fixups decoded; every OFF32 field's raw value == target object offset [C]. | done |
| 0.4 | Function discovery | `tools/find_functions.py` recursive descent + switch tables + gap prologues: 3713 functions, 96.6% of code decoded. | done |
| 0.5 | Split | `tools/split.py` → `asm/DOS/nonmatchings/<func>.s`. | done |
| 0.6 | Compiler pin | Open Watcom 1.9 / 2.0 `wcc386 -s -of+ -5r -omiler -zm -zp1` reproduces 3 of 4 probe functions byte-exact. | done |
| 0.7 | Build wiring | `tools/build_kknd.py`: compile, verify (bytes + reloc targets), splice, rewrite LE, SHA-1. | done |
| 0.8 | First OK | Unmodified split rebuilds byte-identical. | done |
| 0.9 | Units | 48 modules from `__FILE__` strings → `configs/DOS/units.csv`, `src/<module>.c` (+ `src/lib/libs.c`). | done |
| 0.10 | decomp.dev | `tools/make_report.py` (objdiff report v2, one unit per source file, game/lib categories) + GitHub Actions artifact. | done |

**Open questions from Phase 0:**
- Exact Watcom version. Runtime banner says 1988-1994 → 10.0/10.0a. Open Watcom (11.0c
  descendant) differs on at least loop layout (func_000121B0). Getting a real Watcom 10.x
  `wcc386` would close this; until then per-function workarounds (see learnings).
- 3.4% of the code object is undecoded: `int nn; ret` thunk tables, dead code, alignment.
  Some "functions" are data (pointer tables) that the gap finder mistook for code
  (e.g. func_00011290). Clean up in 1.x.

## ▶ PHASE 1 — Foundations  ← CURRENT

| # | Step | Notes |
|---|------|-------|
| 1.1 | Data symbols | Symbolise object 3 (0xB0000, 228 KB: strings, tables, BSS). Every fixup target in obj 3 becomes `D_XXXXXXXX`; sizes from neighbouring targets. Emit `include/data.h` externs. |
| 1.2 | String literals | Model Watcom string placement (CONST/CONST2 per module, in source order) so matched C can use literals instead of `extern` D_ strings. Until then: strings are externs. |
| 1.3 | Library labelling | Watcom clib (`clib3r`), MemCheck 3.5, UniVBE, HMI SOS: name by signature (compile OW clib sources → masked-byte match, same idea as OpenWINGS `lib_match.py`). Libraries may stay INCLUDE_ASM or be matched from their own sources. |
| 1.4 | Unit boundaries | Pin each module's first/last function (string-table order, `CONST` layout, call graph locality). |
| 1.5 | Easy tier | Leaf functions, getters/setters, wrappers, init loops across all game modules via `score_functions.py`. |
| 1.6 | Discovery cleanup | Remove data false positives, split merged functions, name the `int` thunks. |
| 1.7 | Patched wcc386 (**in progress**) | Status 2026-09-24: OW 1.9 bootstrapped from source at `D:/programs/re/openwatcom/src19`, patched binary at `D:/programs/re/openwatcom/patched/binnt/wcc386.exe` with the switch-table `cs:` patch (`i86segs.c` `CalcSegment()` returns HW_CS for CG_TBL). Loop-layout / jump-threading patch not finished; patch not yet validated against the full build or written up in `doc/compiler_patch.md`. Build Open Watcom 1.9 from source with switches that restore Watcom 10.x behaviour where they differ (no jump threading of loop-entry conditions, 10.x loop layout). Same idea as DW2's GCC-Enhanced. Or obtain a genuine Watcom 10.0a `wcc386`. Unblocks the `jt` class in `tools/difficult_functions`. |

## ▶ PHASE 2 — Core engine

Main loop (`main.c`), task system (`tasks.c`), memory / files (`files.c`, `ini.c`,
`loadsave.c`, `savegame.c`), input (`key.c`, `key2.c`, `mouse.c`, `mouseptr.c`, `uinput.c`,
`controlc.c`), graphics (`gfx.c`, `vesa.c`, `vid_dump.c`, `effect.c`), sound (`sound.c`),
FMV (`fmv.c`), level loader (LVL/SLV/SON containers, `mob.c` = MOBD sprites).
Name structs as they are proven; catalogue in `STRUCT_FIELDS.md`.

## ▶ PHASE 3 — Gameplay

Units (`units.c`, `infantry.c`, `aircraft.c`, `tanker.c`, `building.c`, `tower.c`,
`outpost.c`, `clanhall.c`, `machshop.c`, `beastenc.c`, `schrap.c`, `bread.c`, `crtgen.c`,
`super.c`), combat (`projectl.c`, `healthbr.c`), AI (`enemyai.c`), map (`uncover.c` fog of war),
missions (`mission.c`, `playctrl.c`), UI (`toolbars.c`, `message.c`).

## ▶ PHASE 4 — Multiplayer

`network.c`, `netz.c`, `netzutil.c`, `netipx.c`, `nipx.c`, `serial.c` (IPX, null-modem, modem).

## ▶ PHASE 5 — Libraries and 100%

Watcom clib, MemCheck, UniVBE, HMI SOS loader: match from their public sources where
available, else keep documented INCLUDE_ASM (still counted separately on the progress table).

## ▶ PHASE 6 — Source port

Once game code is 100%: a portable build (SDL2, 32/64-bit) behind `#ifdef NON_MATCHING`,
keeping the matching build green. Asset pipeline from `dumps/` (LVL / MOBD / VBC / SON) with
the existing extractor work (`../_extract/kknd_extract.py`).

---

## Working rules

- One matched function = one commit. Build gate green on every commit.
- Journal (`DECOMPILATION_LEARNINGS.md`) grows with every non-trivial match.
- Findings about the engine, formats and the exe go in `KKND_NOTES.md` with [C]/[H]/[?] tags.
- Hard functions go to `tools/difficult_functions` with attempt count and best diff.

## Next session — start here

1. ~~Merge `doc/agent_notes/` into the journal and `tools/difficult_functions`~~ (done session 2; `-ot` made global).
2. Finish PLAN 1.7: validate the patched `wcc386` (build must stay `OK`), then the loop patch.
3. Apply unambiguous names from `configs/DOS/name_evidence.csv` to `symbols.txt` in one pass
   (rename across `src/`, regenerate `asm/`).
4. Continue matching by module with `tools/score_functions.py` (parallel agents per module group
   worked well: ~230 matches in one run).

## Session log

### 2026-09-24 — kickoff

Repo created, Phase 0 complete in one session (see `PROGRESS.md`). Key facts: LE data pages are
relative to the stub MZ (0x26654); OFF32 fixup fields hold object-relative offsets; functions are
16-byte aligned with zero fill because of `-zm`; `-of+` gives every function `push ebp; mov
ebp,esp`; `-5r`/`-4r` zero-extends with `and eax,0xff` (`-3r` uses `movzx`). Flags then refined to
`-s -of+ -5r -omiler -zm -zp1` (drop `-ob`). Trivial families automated (`auto_families.py`), switch
tables supported in the build, then four parallel matching agents by module group. End of session:
**327 / 3713 matched**, build `OK`, CI report artifact `DOS_report` green.
