# Naming conventions

Fresh decomp: everything starts as address-based placeholders (`func_000XXXXX`, `D_000XXXXX`,
`field_XX`). Prefer descriptive names as soon as a symbol's role is clear, and add them to
`configs/DOS/symbols.txt` as `Name = 0xVA;` (the build, splitter and report all read it).

Prove new field roles as you go; catalogue them in `STRUCT_FIELDS.md` (create it when the first
real struct is nailed down).

KKND's own strings give many real names for free: error messages quote their function
(`L_LVL_LoadLevel(wait.lvl) failed`, `MIPX_SetupClientConnection(): no free event`,
`nIPX_RelinguishControl()`, `GrabFreeECB()`, `tLoadGameState()`, `Money_spend`). Use them
verbatim — they are the developers' names.

## Scheme

| Kind | Pattern | Examples |
|---|---|---|
| **Function (real name known)** | the original name | `L_LVL_LoadLevel`, `MIPX_Hangup`, `GrabFreeECB` |
| **Module function** | `Module_VerbNoun` | `Mob_LoadSprite`, `Units_Spawn` |
| **Global data** | `Module_Name` (no `g` prefix) | `Units_List`, `Net_Players` |
| **Types** | PascalCase role name | `Unit`, `BuildingInfo` |
| **Struct tags** | `_TypeName` | `struct _Unit` |
| **Known members** | camelCase role | `health`, `owner` |
| **Unknown members** | `field_XX` | keep until the role is proven |
| **Unnamed functions** | `func_000XXXXX` (linear address) | only until matched + understood |
| **Unnamed data** | `D_000XXXXX` | |

## Modules

The module *is* the original source file (`configs/DOS/units.csv`); a function's prefix follows
its file: `main.c` → `Main_`, `units.c` → `Units_`, `enemyai.c` → `EnemyAI_`, `netipx.c` →
`NetIpx_`, `mob.c` → `Mob_`, … Library functions keep their library names (`printf`,
`VBE_init`, `MC_…`, `sosDIG…`).
