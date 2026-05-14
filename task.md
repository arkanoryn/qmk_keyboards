# Create the missing layout

## Important
1. Read the ENTIRE document **before** taking any action!
2. NEVER try to access any other folder than your current folder (~/Code/qmk/qmk_keyboards/)
3. NEVER read the local machine environment
4. NEVER read any file listed in the `.gitignore`

## Context

- We're moving from `users/v1` to `users/v2`, moving part of the work as it makes sense and we're making progress
- I'm currently missing some layers (from `users/v1/layers`) and we want to move them to `users/v2/layers`

## Initialization

- check the work that has been done in `users/v2/layers/symbols.h`

## - Tasks

- [ ] Follow `Workflow` (below) to duplicate and refactor numpad and sound layer
- [ ] Follow `Workflow` (below) to duplicate and refactor config layer
- [ ] Create a `fn` layer; it should have a configuration similar to the numpad but the "sound" commands should be replaced by `__X__` keys. Read https://docs.qmk.fm/keycodes to access all keycodes. I'm refering to the `KC_F1` to `KC_F12` as function keys.


## Workflow

- [ ] check the files in `users/v1/layers`
- [ ] open and read the file relevant for the task you are currently working on
- [ ] create a file with the same name in `users/v2/layers`
- [ ] refactor the newly created file (in `users/v2/layers`) to match the styles of the other already existing files `users/v2/layers`
- [ ] Add or refactor the Thumbclusters to match the section `Thumbclusters` of this file
- [ ] update `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/keymap.c` to consider the newly created layer
- [ ] compile if it works, move on. If you have errors, try to fix it.
- [ ] commit the changes with a relevant message
- [ ] move to the next task

## Thumbclusters

- The Thumbclusters can only have the following cases.
- The Thumbcluster key should be `__<layer name>__THUMBS__` eg: `__FN_THUMBS__`
- You can replace the keys with `__X__` as I don't know yet which keys I'll put there.

```c
// THUMBCLUSTER_LEFT == 5
#if THUMBCLUSTER_LEFT == 5 && THUMBCLUSTER_RIGHT == 4
#define __THUMBS__________ MEH_SPC, SFT_MAGIC, GUI_ESC, ALT_ARCANE, SFT_BSPC, CTL_TAB, ALT_CAPS, DEL_WORD, GUI_DEL, CTL_ENTR
#elif THUMBCLUSTER_LEFT == 5 && THUMBCLUSTER_RIGHT == 5
#define __THUMBS__________ MEH_SPC, SFT_MAGIC, GUI_ESC, ALT_ARCANE, SFT_BSPC, RCTL_TAB, ALT_CAPS, DEL_WORD, GUI_DEL, CTL_ENTR
#elif THUMBCLUSTER_LEFT == 5 && THUMBCLUSTER_RIGHT == 6
#define __THUMBS__________ THUMB_L1, THUMB_L2, THUMB_L3, THUMB_R1, THUMB_R2, THUMB_R3, THUMB_L4, THUMB_L5, THUMB_R4, THUMB_R5, THUMB_R6

// THUMBCLUSTER_LEFT == 6
#elif THUMBCLUSTER_LEFT == 6 && THUMBCLUSTER_RIGHT == 4
#define __THUMBS__________ MEH_SPC, SFT_MAGIC, GUI_ESC, ALT_ARCANE, SFT_BSPC, CTL_TAB, ALT_CAPS, DEL_WORD, GUI_DEL, CTL_ENTR
#elif THUMBCLUSTER_LEFT == 6 && THUMBCLUSTER_RIGHT == 5
#define __THUMBS__________ THUMB_L1, THUMB_L2, THUMB_L3, THUMB_R1, THUMB_R2, THUMB_R3, THUMB_L4, THUMB_L5, THUMB_L6, THUMB_R4, THUMB_R5
#elif THUMBCLUSTER_LEFT == 6 && THUMBCLUSTER_RIGHT == 6
#define __THUMBS__________ THUMB_L1, THUMB_L2, THUMB_L3, THUMB_R1, THUMB_R2, THUMB_R3, THUMB_L4, THUMB_L5, THUMB_L6, THUMB_R4, THUMB_R5, THUMB_R6
#endif
```
