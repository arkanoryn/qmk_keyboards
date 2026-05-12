# Step 02 — Rework Combo Generation for Multi-Layout Support

**Priority**: CRITICAL — the current generated combo files have bugs, and the generation scripts need to be ported and extended to support per-layout combos.

## Problem Summary

1. V2's `combos/generated/` files were manually created with bugs (`_COMBO_COMBO` naming, incomplete externs, PRODUCT typo on keymap.c:316).
2. V1's Python generator scripts (`users/v1/scripts/generator/`) only support Graphite. V2 needs to support Graphite, Qwerty, Sturdy, and Colemak.
3. The generator should produce all outputs: PROGMEM key arrays, enums, combo_t arrays, command strings, `keymap.c` combo entries — so nothing is manually maintained.
4. `COMBO_ONLY_FROM_LAYER 0` must be removed; combos need to fire on whichever base layer is active.

## Background: How V1 Generation Works

The v1 generator reads CSV files from `definitions/` with format:
```
NAME, STR, CAN_CYCLE, IS_ACTION, KEY1, KEY2, ...
```

Each CSV starts with `prefix,GRAPHITE`. The generator prefixes all names and keys with this prefix. For example, a row `AND,and,,NO,N,D,A` produces:
- Enum: `GRAPHITE_AND`
- Array: `const uint16_t PROGMEM GRAPHITE_AND_COMBO[] = {GRAPHITE_N, GRAPHITE_D, GRAPHITE_A, COMBO_END};`
- combo_t: `[GRAPHITE_AND] = COMBO_ACTION(GRAPHITE_AND_COMBO)`
- Command: `[GRAPHITE_AND] = "and"`

The key aliases (`GRAPHITE_N`, `GRAPHITE_A`, etc.) resolve to physical matrix positions via defines in `graphite.h` (e.g., `#define GRAPHITE_N GRAPHITE_2_01`). This is how combos know which physical keys trigger them.

## Key Insight: Per-Layout Combo Architecture

Word combos are **layout-specific** because the same word uses different physical key positions on different layouts. "AND" on Graphite triggers with keys at positions `GRAPHITE_N`, `GRAPHITE_D`, `GRAPHITE_A` — but on Qwerty, "AND" would need `QWERTY_A`, `QWERTY_N`, `QWERTY_D` (which map to different physical positions).

Each layout already defines key aliases in v2:
- `users/v2/layers/layouts/graphite.h`: `#define GRAPHITE_A GRAPHITE_2_08` etc.
- Similar aliases are needed for Qwerty, Sturdy, Colemak (check if they exist; if not, create them).

## Tasks

### 2.1 Copy v1 scripts to v2

```bash
cp -r users/v1/scripts users/v2/scripts
```

Result:
```
users/v2/scripts/generator/
├── main.py
├── generate_combos.py
├── generate_cycles.py
├── generate_teacher.py
├── global_variables.py
├── common.py
└── definitions/
    ├── graphite_cmd.csv
    ├── graphite_dict_100.csv
    ├── graphite_dict_1000.csv
    └── graphite_dict_personal.csv
```

### 2.2 Use shared word list with layout-specific key mapping

The same words are used across all layouts — only the physical key positions differ. The CSV KEY columns already use bare letter names (A, N, D) that get prefixed at generation time. The generator will iterate over all layouts and re-prefix the keys for each one.

Keep one master set of CSV files (the existing `graphite_*.csv` files). The `prefix` row in each CSV will be ignored by the new multi-layout generator — instead, `main.py` will override the prefix for each layout pass.

### 2.3 Verify/create key aliases for all layouts

Check each layout header for letter-to-position aliases:

**File**: `users/v2/layers/layouts/graphite.h` — has `GRAPHITE_A` through `GRAPHITE_Z` (confirmed)

**File**: `users/v2/layers/layouts/qwerty.h` — check if `QWERTY_A` through `QWERTY_Z` exist. If not, create them following the same pattern:
```c
/* Letter aliases for combo key references */
#define QWERTY_A QWERTY_2_01   /* A is at row 2, col 1 on QWERTY */
#define QWERTY_B QWERTY_3_05
/* ... etc for all 26 letters */
```

Repeat for `sturdy.h` and `colemak.h`.

Also check/add aliases for special combo keys used in `graphite_cmd.csv`:
- `GRAPHITE_SPC`, `GRAPHITE_BSPC`, `GRAPHITE_ENT`, `GRAPHITE_MAGIC`, `GRAPHITE_COMM`, `GRAPHITE_QUOT`
- These need equivalents: `QWERTY_SPC`, `QWERTY_BSPC`, etc. (they may map to the same physical positions if thumb keys don't change between layouts).

### 2.4 Update `global_variables.py`

Change output paths to point to `users/v2/combos/generated/`:

```python
# Output directory (relative to script location)
OUTPUT_DIR = os.path.join(os.path.dirname(__file__), '..', '..', 'combos', 'generated')
```

Update the header include from `"ark_v1.h"` to `"farkann_v2.h"`.

### 2.5 Rework `main.py` for multi-layout

Update `main.py` to:
1. Accept a list of layout prefixes: `["GRAPHITE", "QWERTY", "STURDY", "COLEMAK"]`
2. For each prefix, read the **same** CSV word definitions
3. Re-prefix the keys for each layout
4. Generate combined output that includes all layouts

```python
LAYOUTS = ["GRAPHITE", "QWERTY", "STURDY", "COLEMAK"]

all_combos = []
for layout in LAYOUTS:
    for csv_file in definition_files:
        rows = read_csv(csv_file)
        for row in rows:
            # Override the prefix from the CSV with the current layout
            all_combos.append((layout, row))

generate_combos(all_combos)
generate_cycles(all_combos)
generate_teacher(all_combos)
```

### 2.6 Fix the naming bug in `generate_combos.py`

The `_COMBO_COMBO` double suffix comes from the array naming logic. Trace the `build_combo_name()` function and the array name construction. The pattern should be:
- Enum value: `GRAPHITE_AND` (no suffix)
- PROGMEM array: `GRAPHITE_AND_COMBO` (one `_COMBO` suffix)
- In `COMBO()` / `COMBO_ACTION()`: `COMBO_ACTION(GRAPHITE_AND_COMBO)` referencing the array

Ensure `generate_combos.py` does NOT append `_COMBO` to a name that already has it.

### 2.7 Generate a `keymap_combos.inc` file for keymap.c

Currently the `combos[]` array in `keymap.c` is manually maintained (~240 lines). The generator must produce a `generated/keymap_combos.inc` file that keymap.c `#include`s:

```c
/* In keymap.c — replace the entire manually-written combos[] array with: */
const combo_t PROGMEM combos[] = {
#include "combos/generated/keymap_combos.inc"
};
```

The generator produces each line of the `.inc` file in the format:
```c
COMBO_ACTION(GRAPHITE_AND_COMBO),   /* [GRAPHITE_AND] */
COMBO(GRAPHITE_TAB_C_COMBO, KC_TAB), /* [GRAPHITE_TAB_C] - ACTION type */
```

### 2.8 Remove `COMBO_ONLY_FROM_LAYER 0`

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/config.h`

Remove or comment out:
```c
// #define COMBO_ONLY_FROM_LAYER 0
```

Instead, use `combo_should_trigger()` (already defined in `combos/combos.c`) to restrict combos to their matching base layer:

```c
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (combo_index == GRAPHITE_CONFIG_LAYER) { return true; }

    /* Only fire combos when their layout layer is active */
    if (combo_index >= GRAPHITE_FIRST_COMBO && combo_index <= GRAPHITE_LAST_COMBO) {
        return layer_state_is(_GRAPHITE);
    }
    if (combo_index >= QWERTY_FIRST_COMBO && combo_index <= QWERTY_LAST_COMBO) {
        return layer_state_is(_QWERTY);
    }
    if (combo_index >= STURDY_FIRST_COMBO && combo_index <= STURDY_LAST_COMBO) {
        return layer_state_is(_STURDY);
    }
    if (combo_index >= COLEMAK_FIRST_COMBO && combo_index <= COLEMAK_LAST_COMBO) {
        return layer_state_is(_COLEMAK);
    }

#ifdef CHORD_TEACHER_ENABLE
    if (get_teacher_chord_mode() == TEACHER_CHORD_MODE_OFF) { return false; }
#endif

    return true;
}
```

The generator should emit `GRAPHITE_FIRST_COMBO`, `GRAPHITE_LAST_COMBO` etc. sentinel values in the enum to make this range check work.

### 2.9 Update the generated enum structure

The enum in `generated/combos.h` should be structured per-layout with sentinels:

```c
enum combos {
    /* Graphite combos */
    GRAPHITE_FIRST_COMBO = _FIRST_COMBO_ID,
    GRAPHITE_DEL_WORD = GRAPHITE_FIRST_COMBO,
    GRAPHITE_CONFIG_LAYER,
    /* ... all graphite combos ... */
    GRAPHITE_LAST_COMBO,

    /* Qwerty combos */
    QWERTY_FIRST_COMBO,
    QWERTY_DEL_WORD = QWERTY_FIRST_COMBO,
    /* ... all qwerty combos ... */
    QWERTY_LAST_COMBO,

    /* ... Sturdy, Colemak ... */

    _LAST_COMBO_ID
};
```

### 2.10 Fix PRODUCT combo bug in enum

**File**: `users/v2/combos/generated/combos.h`, line 247

The enum entry `GRAPHITE_PRODUCT_COMBO` has a `_COMBO` suffix that doesn't belong — it should be `GRAPHITE_PRODUCT`. This will be fixed automatically when the generator is re-run, but verify the CSV source doesn't have a naming issue.

### 2.11 Update `combos.c` for multi-layout

The `process_combo_event()` function in `combos/combos.c` handles combo actions by enum value. With multi-layout combos, the same word (e.g., "and") will have different enum values per layout (`GRAPHITE_AND`, `QWERTY_AND`, etc.) but the **same action** (send "and").

The existing `default:` case in `process_combo_event()` already calls `get_combos_cmds(combo_index)` and `send_string()`, so it handles all word combos for all layouts automatically — the generator just needs to populate the `combo_cmds[]` array for all layout entries.

For special combos (`DEL_WORD`, `SFT_ENT`, `C_ENT`, `CONFIG_LAYER`), add per-layout cases that fall through to the same handler:
```c
case GRAPHITE_DEL_WORD:
case QWERTY_DEL_WORD:
case STURDY_DEL_WORD:
case COLEMAK_DEL_WORD:
    process_del_word();
    break;
```

### 2.12 Run generator and verify

```bash
cd users/v2/scripts/generator
python main.py
```

Then:
```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

### 2.13 Delete manually-created generated files

After confirming the generator output is correct, the old manually-created `combos/generated/combos.c` and `combos.h` are replaced by the generator output. The keymap.c `combos[]` array should be replaced with an `#include` of the generated file.

## Verification

1. `python users/v2/scripts/generator/main.py` runs without errors
2. Generated files have no `_COMBO_COMBO` naming
3. All externs are complete
4. `qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2` succeeds
5. Flash and test: combos fire on Graphite, switch to Qwerty — combos still fire with Qwerty key positions

## Files Created/Modified

| File | Action |
|------|--------|
| `users/v2/scripts/` | CREATE (copy from v1, then modify) |
| `users/v2/scripts/generator/main.py` | EDIT — multi-layout support |
| `users/v2/scripts/generator/generate_combos.py` | EDIT — fix naming, multi-layout |
| `users/v2/scripts/generator/generate_cycles.py` | EDIT — multi-layout |
| `users/v2/scripts/generator/generate_teacher.py` | EDIT — multi-layout |
| `users/v2/scripts/generator/global_variables.py` | EDIT — output paths, header refs |
| `users/v2/layers/layouts/qwerty.h` | EDIT — add key aliases if missing |
| `users/v2/layers/layouts/sturdy.h` | EDIT — add key aliases if missing |
| `users/v2/layers/layouts/colemak.h` | EDIT — add key aliases if missing |
| `users/v2/combos/generated/combos.c` | REGENERATED |
| `users/v2/combos/generated/combos.h` | REGENERATED |
| `users/v2/combos/combos.c` | EDIT — multi-layout case handling |
| `keyboards/.../keymaps/v2/config.h` | EDIT — remove COMBO_ONLY_FROM_LAYER |
| `keyboards/.../keymaps/v2/keymap.c` | EDIT — use #include for combos array |

## Dependency Note

This step should be done **before** Step 10 (which was originally about code generation). With this plan, Step 10 becomes unnecessary — merge its concerns into this step. Update `00-overview.md` accordingly.
