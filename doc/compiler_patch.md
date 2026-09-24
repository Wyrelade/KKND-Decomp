# Patched `wcc386` (PLAN 1.7)

KKND was built with Watcom C/C++32 10.0/10.0a. Open Watcom descends from Watcom 11.0c, so a few
code-generator decisions changed between the two. This patch set puts the Watcom 10.x
behaviour back into an Open Watcom 2.0 `wcc386`, the same approach as the DW2 decomp's
"GCC-Enhanced". Status: the patched compiler is the project's default toolchain (2026-09-24,
session 2). The full build stays `OK` with it, and it unblocks switch tables and the `jt`
loop class.

- Patch: [`tools/owpatch/kknd-wcc386.patch`](../tools/owpatch/kknd-wcc386.patch)
  (`git diff` against open-watcom-v2 commit `91922eabf98fdfbc38de8ddd4ff3e7f5e769c64c`).
- Binary: `D:/programs/re/openwatcom/patched/binnt/wcc386.exe` (headers in `patched/h`).
  `tools/match.py` picks it after `$WATCOM` and `tools/watcom/`, before stock OW 1.9.
- Every behaviour change is also reachable through an environment variable, so experiments do
  not need a rebuild.

## What the patch changes

| File | Default behaviour now | Env to get stock OW back | Evidence |
|---|---|---|---|
| `cg/intel/c/x86segs.c` `CalcSegment()` | switch jump tables are read through `cs:` in the flat model (`2e ff 24 85 ...`) | none | all 36 retail jump tables use `jmp dword ptr cs:[reg*4+tbl]` |
| `cg/intel/c/x86sel.c` `Balance()` | size/time floor for the switch-strategy cost is 15 (OW: 25). `KKND_SWOPT=<n>` sets any value | `KKND_SWOPT=25` | func_000323B0 (4 cases over 0..11 becomes a table) needs < 20; func_0003DCA0 (16 cases over 0x5D9..0x60B stays a binary tree) needs >= 13 |
| `cg/c/bldsel.c` `DoBinarySearch()` | pure binary search for a 3-case node (`cmp c2; jb lt; jbe l2; cmp c3; je l3; jmp dflt; lt: cmp c1; je l1; jmp dflt`) | `KKND_LINSEL=1` (OW's linear shortcut) | func_0001CDC4 |
| `cg/intel/c/x86enc2.c` `DepthAlign()` | no alignment padding anywhere: not at loop heads (`-ot` pads deep loops to 16 with `lea` NOPs) and not at the code after a jump table | `KKND_LOOPALIGN=1` | no `lea r,[r]` NOPs in the whole retail exe; func_0001CDC4 code starts right after its 20-byte table |
| `cg/c/cse.c` `CommonSex()` | `StretchEdges()` is off: no jump threading of a condition known on loop entry | `KKND_STRETCH=1` | func_000121B0 (`for (i = 0; i < 0xC4; i++) if (i != 0x54) f(i);`) |
| `cg/c/loopopts.c` `TwistLoop()` | a single-exit loop whose condition cannot be copied into the preheader is entered at its bottom test (`jmp test; body; test: jcc body`) | `KKND_NOROT=1` | func_00053700 (`if (p) for (; n > 0; n--) *p++ = 0;`) |
| `cg/intel/386/c/386rgtbl.c` `DoubleRegs[]` | 32-bit register preference EAX, EDX, **EBX, ECX**, ESI, EDI (OW: ECX before EBX; the 16-bit `WordRegs` table already had BX first) | `KKND_ECXFIRST=1` | func_0002E940 (`rp` class) now matches; no earlier match lost |
| `cg/intel/c/x86mul.c` `MulCost()` | multiply cost uses the 386/486 early-out estimate (4 + bits of the constant) for every 32-bit CPU level, so `-5r` strength-reduces like Watcom 10 | `KKND_OWMUL=1` | retail never uses `imul reg,reg,K` for struct indexing (`mul` class) |
| `cg/c/multiply.c` `Factor()` | the trailing power of two is shifted last: `n*56` = `((n<<3)-n)<<3` (`lea edx,[ecx*8]; sub edx,ecx; shl edx,3`) | `KKND_OWFACTOR=1` | func_0001C260 instruction sequence |
| `cg/c/blktrim.c` `Retarget()` | experiment only, off by default: `KKND_NORETRET=1` stops retargeting a conditional jump to a return block | (default is stock) | lets a goto-shaped func_00053700 match; not needed with the loop patch |

The `KKND_*` variables are read with `getenv()` in the code generator, so they apply to a whole
compile. Keep the defaults for real work. Use the variables only to test a hypothesis, then bake
the result into the default.

## Rebuild

The OW 2.0 source tree is at `D:/programs/re/openwatcom/patched/src2`. It was bootstrapped once
with `doboot.bat` (it calls `build.bat boot` under `mysetvars.bat`, with a stock OW 2.0 in
`D:/programs/re/openwatcom/ow2` as the host compiler). After that an incremental rebuild of only
the code generator and the C front end takes seconds:

```sh
cd /d/programs/re/openwatcom/patched
sh rb.sh          # runs rebuild.bat: wmake cg/intel/386/binbuild + cc/386/binbuild,
                  # copies bwcc386.exe to binnt/wcc386.exe; prints REBUILD-OK
sh runtests.sh    # tests/t*.c probes through tools/match.py
```

From scratch on a new machine:

1. `git clone https://github.com/open-watcom/open-watcom-v2 src2 && cd src2 && git checkout 91922eab`
2. `git apply <repo>/tools/owpatch/kknd-wcc386.patch`
3. Set `OWROOT` to `src2` and put a stock OW 2.0 on `PATH`/`WATCOM` (see `mysetvars.bat`), then
   `build.bat boot` once.
4. `rebuild.bat` (or the two `wmake -h -f ../binmake bootstrap=1` calls in it) and copy
   `bld/cc/386/binbuild/bwcc386.exe` to `<dir>/binnt/wcc386.exe` next to a copy of OW's `h/`.
5. Point `WATCOM` at `<dir>` (or copy it to `tools/watcom/`) and run `python tools/build_kknd.py`.

OW 2.0 is stricter than 1.9 about function-pointer assignments (`E1010 Type mismatch`); cast
explicitly, e.g. `a->field_10 = (int (*)())func_00046920;`.

## Still open (candidates for the next patches)

These classes have no source-level fix. See `tools/difficult_functions` for the tagged lists and
`DECOMPILATION_LEARNINGS.md` for examples.

- `mul` register choice: with the sequence now right, func_0001C260 still keeps a different value
  in ECX vs the stack slot (register allocation around the multiply temp).
- `ci`: Watcom 10 loads constants into a register before storing them to memory.
- `fold`: Watcom 10 loads a memory operand into a register before an ALU op.

## Experiments in the patch (off by default)

- `KKND_CONSTREG=1`: cache constants stored to globals in registers, never in EAX
  (`cachecon.c` `KKNDConstToTempFunc`, `regalloc.c`, `x86regsv.c`). One earlier variant matched
  func_0004CDC0, but caching every constant cost 182 matches. The global-store-only variant
  loses no match but the temp is copy-propagated away before allocation. Unfinished.
- `KKND_REGORDER=adbcsi` sets the 32-bit register order; every order other than the default lost
  57-150 matches. `KKND_CONFREV=1` (reverse conflict ties) lost 21.
- The installed `patched/binnt` binary predates these; `patched/next/binnt` has them
  (`rbn.sh` rebuilds only `next`).
