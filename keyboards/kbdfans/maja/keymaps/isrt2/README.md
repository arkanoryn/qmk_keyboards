# Todos

im not entirely sure how it is done, but you could define a "target" on your mk file to re-generate the files automatically, as part of the compilation process, when they get changed. from the top of my head, it would look something like
```c
# NOTE: im not sure if folder name/wildcard works
# syntax here is `files_that_change: they_change_based_on_these`
$(USER_PATH)/combos/generated*: $(USER_PATH)/combos/definitions/*
  $(shell python $(USER_PATH)/combos/scripts/parser.py im_lazy_to_finish)
```

- rework the python script
```py
f = open(...)
...
f.close()

# more like
with open(...) as f:
    ...
# once here (un-indented), cleanup is run magically ^^
# ```

## Leader and Combos Improvements
- [X] Look after the Comb, chords etc
- [X] Look for Magic and Repeat - https://github.com/MightyAcas/vylet#magic-key
- [X] Cycle: manage shift
- [X] Implement "repeat" logic
- [X] Implement "select word" logic
- [X] Backspace combo (if combo) otherwise bspc word
- [X] reinitialize combo status after X sec
- [ ] Correction logic: if a chord exist for the current word, propose it instead
- [ ] Correction logic: force the use of the "repeat" key
- [ ] modify SEL_WORD so that it can go backward (with shift) and with line (double tap?)
- [ ] review the swapper logic like here https://github.com/rafaelromao/keyboards/blob/main/docs/shortcuts.md#swapper
- [ ] add sentence capitalization
- [ ] Reduce the times between input and actions from leader
- [ ] Add new lead functions (close tab, new private win, CTRL+1-5, smileys)
- [ ] Refresh page
- [ ] ALFRED
- [ ] CTRL/CMD + / for commenting lines
- [ ] manage the shift = oneshot SFT when chording

## Readme Improvements
- [ ] add the keydrawer PNG to the README
- [ ] Rework the home README
- [ ] Add licenses etc

## RGB
- [ ] Manage RGB - https://getreuer.info/posts/keyboards/triggers/index.html / https://getreuer.info/posts/keyboards/macros3/index.html#blinking-leds
- [ ] Manage OLED screen

## Home Row Improvements
- [X] Look at `Permissive_HOLD` in QMK
- [ ] Look at Achordion - https://getreuer.info/posts/keyboards/achordion/index.html

## Layers Improvements
- [X] see if we can replace selections with [select_word](https://github.com/getreuer/qmk-keymap/blob/main/features/select_word.c)
- [ ] Revisit the [symbol layer](https://getreuer.info/posts/keyboards/symbol-layer/index.html)
- [ ] Disable action if idle (see https://getreuer.info/posts/keyboards/triggers/index.html#when-idle-for-x-milliseconds)
- [ ] Autocorrection https://getreuer.info/posts/keyboards/autocorrection/index.html
- [ ] oneshot modifier if both are pressed
- [ ] Add most used emoji and ([random emojis](https://getreuer.info/posts/keyboards/macros3/index.html#random-emojis))

## Done
- [X] Accents for MacOS.
- [X] Move TAB to DF instead of current spot
- [X] Change the fancy LT etc keycode to define for cleaner keymap
- [X] Add the circonflexe on the symbol layer

### Symbols and Shortcuts
- [X] Fix the EURO Keycaps
- [X] CTRL+ALT+SUPP shortcut for winOS

## Layers Managements
- [X] Lock / Unlock current layer - https://getreuer.info/posts/keyboards/layer-lock/index.html


# Reading Lists

- https://github.com/getreuer/qmk-keymap/blob/main/features/select_word.c
- https://getreuer.info/posts/keyboards/index.html
- https://github.com/precondition/dactyl-manuform-keymap
