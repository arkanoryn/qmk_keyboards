# READ ME

This Read Me is dedicated to the drawer script and how to run it
in order to update the visual keymap.

These instructions are limited to the Aurora Sweep configuration.
The Maja will have its own (eventually).

## Prerequisite

- You must have QMK installed on your computer. See instructions [here](https://docs.qmk.fm/newbs_getting_started).
- You must first install `keymap-drawer`. For that, follow the instructions [here](https://github.com/caksoylar/keymap-drawer?tab=readme-ov-file#usage).

## Run

The following instructions must be run in your shell, from the root of your qmk_user folder.

```shell
cd <qmk_user_folder>
 qmk c2json --no-cpp ./keyboards/splitkb/aurora/sweep/rev1/keymaps/v1/keymap.c | keymap parse -c 10 -q - > keyboards/splitkb/aurora/sweep/rev1/keymaps/v1/scripts/drawer/raw_sweep_keymap.yaml
 python3 ./keyboards/splitkb/aurora/sweep/rev1/keymaps/v1/scripts/drawer/sweep_keymap.py
```

Then you can paste the results from the file `./keyboards/splitkb/aurora/sweep/rev1/keymaps/v1/scripts/drawer/sweep_keymap.yaml` into [keymap-drawer](https://keymap-drawer.streamlit.app/) form.
I also left a CSS config if you want. You can find it in the same folder as the keymap.
