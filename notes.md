CS=GP6
Reset=GP7
AO=GP8

SCK=GP27
SDA=GP26

https://www.raspberrypi.com/documentation/microcontrollers/pico-series.html

Trackball pinout:
SCK GP2
MOSI: GP3
MISO: GP4
SS: GP5
Trackball is explicitly SPI (AFAIK SPI bus 0)

# TODOs

- [ ] clean up:
    - [ ] accents
    - [ ] config
    - [ ] numpad
    - [ ] symbols
- [ ] rework completely the actions based on the clean up I did and forgot to merge. To consider: should I merge and rebase?
- [ ] Screens
    - [ ] Talk with QMK and see how I can differentiate both screens
    - [ ] Create a default picture for the screen when the default keymap from QMK gets compiled/based
    - [ ] Code a way for the Screen to display the keys of the current layer. We might need to create another python script; tbd.
- [ ] Make a script to compile my personal keymap
- [ ] Make a script with input that Skree and I can use for customers with the proper prompts so that we do not have to think...

