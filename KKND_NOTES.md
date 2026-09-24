# KKND — project notes / findings

Findings about the executable, toolchain, engine and data formats. Tags: **[C]** confirmed,
**[H]** hypothesis, **[?]** unknown. Addresses are linear addresses (LE object base + offset).

## Disc

- Source: retail KKND CD (DOS), copied to `dumps/disc/` (gitignored).
- Root: `INSTALL.EXE`, `DETAL.EXE` (hardware detection), `UVCONFIG.EXE` (UniVBE config),
  `HMIDET.386` / `HMIDRV.386` (HMI SOS detection / driver bundles), `AUTORUN.INF`, `README.TXT`.
- `KKND/`: `KKND.EXE` (the target), `UNITS.CFG`, `SERIAL.CFG`, `KKNDINS.CFG`, `KILLKKND.BAT`,
  `MAXIMUM.LST` / `MINIMUM.LST` (install lists), `FMV/*.VBC` (33 videos), `LEVELS/`.
- `KKND/LEVELS/640/*.LVL`: 15 Survivor + 15 Evolved missions (`SURV_nn`, `MUTE_nn`),
  10 multiplayer maps (`MLTI_nn`), `SPRITES.LVL`, `SUPSPR.LVL`, `SUPER.LVL`, `FMV.LVL`, `INSTALL.LVL`,
  `WAIT.LVL`, `INSWAIT.LVL`. `LEVELS/*.SLV` / `*.SON` = sound banks / music, `MULTI.PAL` palette.
- The exe also references `msur_nn.lvl` / `mmut_nn.lvl` (multiplayer survivor / mutant variants)
  that are **not** on this disc [C] (strings at 0xB03DC..0xB04C0).
- This is the original DOS KKND (1997), not the later Windows "KKND Xtreme" re-release.

## KKND.EXE layout [C]

| Item | Value |
|---|---|
| Size / SHA-1 | 1,062,709 bytes / `024e96860c504b462b24b9237d49bfe8de6eb8e0` |
| MZ stub | DOS/4GW Professional loader ("Rational Systems 1990-1994"), bound |
| LE header | file 0x28FEC, owned by the stub MZ at 0x26654 (its 0x3C = 0x2998) |
| Data pages | LE `data pages offset` 0x2CE00 is **relative to the stub MZ** → file 0x53454 |
| Page size | 4096, 177 pages, last page 737 bytes; no iterated/compressed pages |
| Entry | obj 1 + 0x28354 = **0x38354** (Watcom `_cstart_`, `jmp` over the runtime banner) |
| Stack | obj 3, ESP 0x37AF0 (top of object 3) |

| Obj | Base | Virtual size | Flags | Role |
|---|---|---|---|---|
| 1 | 0x010000 | 0x08E630 (583,216) | 0x2045 exec, 32-bit | code (+ switch tables) |
| 2 | 0x0A0000 | 0x0043EE (17,390) | 0x1045 exec, **16-bit** | real-mode / 16-bit stubs (callbacks, drivers) [H] |
| 3 | 0x0B0000 | 0x037AF0 (228,080) | 0x2043 data, 32-bit | DGROUP: data, strings, BSS, stack |

Fixups (20,192): OFF32 → obj 3 (17,288, data refs), OFF32 → obj 1 (2,899: function pointers,
switch tables), 3 selector fixups to obj 3, 1 OFF16 + 1 OFF32 to obj 2. No REL32 fixups (intra-
object `call rel32` is resolved at link time) [C]. **Every OFF32 field in the file holds the
target's object-relative offset** (the loader adds the object base) [C] — `le.load(relocate=True)`
applies them for analysis; the build compares unrelocated bytes.

## Toolchain [C unless tagged]

- Compiler: **Watcom C/C++32**, runtime banner "WATCOM C/C++32 Run-Time system. (c) Copyright by
  WATCOM International Corp. 1988-1994" (0x7B7A9) → Watcom 10.0/10.0a [H].
- Build date `Feb 16 1997` (`__DATE__` string at 0xB00EC).
- Language: C. 48 game modules name themselves via `__FILE__` (error/assert strings).
- Flags reproducing the code: `-s -of+ -5r -omiler -zm -zp1` (see `COMPILER_ANALYSIS.md`).
- Libraries linked: Watcom clib (`_cstart_` 0x38354; clib body from ~0x710B5), StratosWare
  **MemCheck 3.5** (build `Jun 25 1996`, `MEMCHECK.LOG`, `MCBRAND.EXE` messages), SciTech
  **UniVBE** / VBE-AF (`Sep 04 1996 - Build 53`, `univbe.drv`, `VBEAF.DRV`), **HMI SOS** driver
  loader (`hmidrv.386`, `hmidet.386`, `XXDEF.C`, `XERFTRC.C`).
- Beam Software credit string: "Beam Software Pty. Ltd." (0xC2135 region).

## Source modules (link order) [C for membership, H for exact boundaries]

From the functions that reference each `__FILE__` string (`configs/DOS/units.csv`):

`main.c` 0x10010 · `misc.c` 0x112B0 · `network.c` 0x12550 · `mouseptr.c` 0x15920 ·
`tasks.c` 0x19E30 · `mob.c` 0x1A3D0 · `key.c` 0x1AE50 · `mouse.c` 0x1B250 · `sound.c` 0x1B7E0 ·
`units.c` 0x1E310 · `netz.c` 0x1F470 · `fmv.c` 0x202A0 · `loadsave.c` 0x20B60 · `gfx.c` 0x27184 ·
`effect.c` 0x28040 · `crtgen.c` 0x285D0 · `netzutil.c` 0x29650 · `toolbars.c` 0x2A410 ·
`aircraft.c` 0x2CD40 · `playctrl.c` 0x2F200 · `mission.c` 0x30E00 · `super.c` 0x32430 ·
`clanhall.c` 0x39760 · `outpost.c` 0x3A060 · `beastenc.c` 0x3BCF0 · `infantry.c` 0x3D930 ·
`tower.c` 0x46CA0 · `tanker.c` 0x49210 · `machshop.c` 0x498A0 · `uinput.c` 0x4A010 ·
`message.c` 0x4B570 · `netipx.c` 0x4C1E0 · `building.c` 0x4EC30 · `uncover.c` 0x4F670 ·
`bread.c` 0x52AE0 · `schrap.c` 0x55D70 · `projectl.c` 0x56440 · `enemyai.c` 0x58960 ·
`healthbr.c` 0x5C9F0 · `serial.c` 0x5E360 · `vid_dump.c` 0x60640 · `vesa.c` 0x68220 ·
`files.c` 0x68B80 · `ini.c` 0x68FE0 · `controlc.c` 0x6B540 · `savegame.c` 0x6C460 ·
`key2.c` 0x6C710 · `nipx.c` 0x70530 · libraries 0x710B5+.

Names that appear as strings but are not referenced by code: `RE_detenshn.c`, `binfantry.c`,
`err.c`, `jscar.c`, `rnienemyai.c` (string fragments of longer names or dead references) [?].
The `_cstart_` entry (0x38354) sits between `super.c` and `clanhall.c`, and "Warning: out of
enemy nodes" code sits at 0x75280 in the library region — so link order is not strictly
game-then-libraries [H: startup object linked mid-list; an AI helper module after clib].

## Code object facts

- Functions are **16-byte aligned, zero-filled** between them [C] (`-zm` = one segment per function).
- Every game function has a frame: `push ebp; mov ebp,esp … mov esp,ebp / lea esp,[ebp-n]; pop ebp` [C].
- Some functions are far with the `inc ebp; push ebp … pop ebp; dec ebp; retf` Windows-style
  frame marker (e.g. 0x10EB0) [C] — interrupt / DOS4GW callbacks [H].
- 32 switch jump tables in the code object: `jmp dword ptr cs:[reg*4 + table]`, tables inside
  the code object, entries are OFF32 fixups to code [C].
- Watcom `int nn; ret` thunk arrays (e.g. 0x6CCF9, 0x6CDBF, 0x92463, 0x9256B) = `int386`-style
  interrupt callers [C shape, H use].

## Data formats (from the extractor work in `../_extract/`)

- `.LVL` container: `"DATA"` + BE length, inner stream from byte 8: int32 file-type-list
  offset → `[FourCC + offset]` table → per-type file offset lists [C].
- Sprites: `MOBD` → render flags (`SPRT` stored reversed `TRPS`, 12 bytes: tag, flags, image
  offset (inner-stream relative)) → image `width:i32, height:i32, comp:u8, data`, comp 2 = Gen1
  RLE [C]. `flags & 1` = horizontal flip [C].
- Palette `MULTI.PAL`: 256 × "R G B" ASCII lines, index 0 transparent [C].
- `.VBC` FMV, `.SON` / `.SLV` audio: [?] — the FMV / sound code in `fmv.c` / `sound.c` is the spec.

## Real function names (from diagnostics) [H per name]

Beam's error strings name the function that prints them (`NetworkEvent(): Invalid client
connect`, `NETZ_Send(): send to NULL link`, `FatalNetError(): Null task ptr`, `GetFreeColour()`,
`AddToAddrList()`, `tLoadGameState()`, `MIPX_SetupClientConnection()` …). `tools/name_evidence.py`
collects them into `configs/DOS/name_evidence.csv`: 131 self-name hints over 66 functions, 56 of
them unambiguous. Naming convention visible: `NETZ_` (network abstraction, `netz.c`), `MIPX_`/
`nIPX_` (IPX driver, `netipx.c`/`nipx.c`), `LVL_` (level container loader), `L_LVL_` wrappers.
They go into `configs/DOS/symbols.txt` once the function has been read (renames are applied in
one pass across `src/` because the asm listings are named after symbols).

## Library identification

Masked prefix matching of Open Watcom 1.9 `clib3r.lib` / `math3r.lib` / `math387r.lib` against
every function (`tools/lib_match.py`) finds only ~8 hits, several spurious: KKND's Watcom 10.0
runtime differs from Open Watcom's (descended from 11.0c) in almost every routine [C]. Library
labelling needs the Watcom 10.x libraries themselves, or manual identification by behaviour.
