RAW_FILEPATH = "./keyboards/splitkb/aurora/sweep/rev1/keymaps/v1/scripts/drawer/raw_sweep_keymap.yaml"
FIXED_FILEPATH = "./keyboards/splitkb/aurora/sweep/rev1/keymaps/v1/scripts/drawer/sweep_keymap.yaml"

CTL = "⌃"
CMD = "⌘"
ALT = "⎇"
ENTER = "⏎"
TAB = "⇥"
CAPS_LOCK = "⇪"
SHIFT = "⇧"
OPT = "⌥"
DELETE = "⌦"
BSPC = "⌫"
HOME = "⇱"
END = "⇲"
PG_UP = "⇞"
PG_DOWN = "⇟"
LAYER = "*"
MAGIC = "★"
LAY_ACTIONS = f"{LAYER} Act"
LAY_SYMBOLS = f"{LAYER} Sym"
LAY_ACCENTS = f"{LAYER} Acc"
LAY_NUMPAD = f"{LAYER} Num"
MEH = "☩"
SPACE = "⎵"
ESCAPE = "ESC"
COPY = "⤹"
PASTE = "⤴"
CUT = "✂️"
SELECT = "【】"
PREVIOUS = "⤟"
NEXT = "⤠"
CLOSE = "✗"
REOPEN = "⟲"
LOCK = "∞"
LEFT = "↞"
RIGHT = "↠"
UP = "↟"
DOWN = "↡"
JUMP_LEFT = "⤽"
JUMP_RIGHT = "⤼"
PLAY = "⏯"

replacements = {
    "keyboards/splitkb/aurora/sweep/rev1": "splitkb/aurora/sweep/rev1",
    "LAYOUT": "LAYOUT_split_3x5_2",
    '  X  ': "",
    # layers titles
    "L0:": "Graphite:",
    "L1:": "ISRT:",
    "L2:": "Actions:",
    "L3:": "Symbols:",
    "L4:": "Symbols | Accents:",
    "L5:": "Numpad | Media:",
    # Modifiers
    "CTL L": f"{{t: L, h: {CTL}}}",
    "CTL U": f"{{t: U, h: {CTL}}}",
    "CTL COMM": f"{{t: ',', h: {CTL}}}",
    "CTL C": f"{{t: C, h: {CTL}}}",
    "ALT D": f"{{t: D, h: {ALT}}}",
    "ALT O": f"{{t: O, h: {ALT}}}",
    "ALT L": f"{{t: L, h: {ALT}}}",
    "ALT U": f"{{t: U, h: {ALT}}}",
    "GUI W": f"{{t: W, h: {CMD}}}",
    "GUI F": f"{{t: F, h: {CMD}}}",
    "GUI M": f"{{t: M, h: {CMD}}}",
    # layers modifier (Graphite)
    "L1 S": f"{{t: S, h: '{LAY_ACTIONS}', type: ghost}}",
    "L1 H": f"{{t: H, h: '{LAY_ACTIONS}', type: ghost}}",
    "L2 T": f"{{t: T, h: '{LAY_SYMBOLS}', type: ghost}}",
    "L2 A": f"{{t: A, h: '{LAY_SYMBOLS}', type: ghost}}",
    "L3 R": f"{{t: R, h: '{LAY_ACCENTS}', type: ghost}}",
    "L3 E": f"{{t: E, h: '{LAY_ACCENTS}', type: ghost}}",
    "L4 N": f"{{t: N, h: '{LAY_NUMPAD}', type: ghost}}",
    "L4 I": f"{{t: I, h: '{LAY_NUMPAD}', type: ghost}}",
    "SFT Q": f"{{t: Q, h: '{SHIFT}'}}",
    "SFT SLSH": f"{{t: '/', h: '{SHIFT}'}}",
    # layers modifier (ISRT)
    "L1 T": f"{{t: T, h: '{LAY_ACTIONS}', type: ghost}}",
    "L1 N": f"{{t: N, h: '{LAY_ACTIONS}', type: ghost}}",
    "L2 R": f"{{t: R, h: '{LAY_SYMBOLS}', type: ghost}}",
    "L2 E": f"{{t: E, h: '{LAY_SYMBOLS}', type: ghost}}",
    "L3 S": f"{{t: S, h: '{LAY_ACCENTS}', type: ghost}}",
    "L3 A": f"{{t: A, h: '{LAY_ACCENTS}', type: ghost}}",
    # "L4 I": f"{{t: I, h: '{LAY_NUMPAD}', type: ghost}}", # Same in Graphite & ISRT
    "L4 O": f"{{t: O, h: '{LAY_NUMPAD}', type: ghost}}",
    # "SFT Q": f"{{t: Q, h: '{SHIFT}'}}", # Same in Graphite & ISRT
    "SFT X": f"{{t: X, h: '{SHIFT}'}}",
    # Specials
    "MEH SPC": f"{{t: '{SPACE}', h: '{MEH}'}}",
    "MAGIC": f"{{t: '{MAGIC}'}}",
    "BSPC": f"{{t: '{BSPC}'}}",
    "PENT": f"{{t: '{ENTER}'}}",
    "ENT": f"{{t: '{ENTER}'}}",
    # Actions
    "QK GESC": f"{{t: '{ESCAPE}', s: '`'}}",
    "CKC(CMD COPY)": f"{{t: '{COPY}', h: 'copy'}}",
    "CKC(CMD PASTE)": f"{{t: '{PASTE}', h: 'paste'}}",
    "CKC(CMD CUT)": f"{{t: '{CUT}', h: 'cut'}}",
    "CKC(LINE BACKSPACE)": f"{{t: '{BSPC}', h: 'LINE', s: 'bspc' }}",
    "CKC(WORD BACKSPACE)": f"{{t: '{BSPC}', h: 'WORD', s: 'bspc'}}",
    "CKC(LINE DEL)": f"{{t: '{DELETE}', h: 'LINE', s: 'del'}}",
    "CKC(WORD DEL)": f"{{t: '{DELETE}', h: 'WORD', s: 'del'}}",
    "PGUP": f"{{t: '{PG_UP}', h: 'up', s: 'page'}}",
    "PGDN": f"{{t: '{PG_DOWN}', h: 'down', s: 'page'}}",
    "CKC(LINE SELECTL)": f"{{t: '{SELECT}', h: 'LINE', s: 'slct'}}",
    "CKC(WORD SELECTL)": f"{{t: '{SELECT}', h: 'WORD', s: 'slct'}}",
    "CKC(APP PREV)": f"{{t: '{PREVIOUS}', h: 'App', s: 'prev'}}",
    "CKC(APP NEXT)": f"{{t: '{NEXT}', h: 'App', s: 'next'}}",
    "HOME": f"{{t: '{HOME}', h: 'HOME', s: ''}}",
    "END": f"{{t: '{END}', h: 'END', s: ''}}",
    "CKC(TAB CLOSE)": f"{{t: '{CLOSE}', h: 'Tab', s: 'close'}}",
    "CKC(TAB REOPEN)": f"{{t: '{REOPEN}', h: 'Tab', s: 'open'}}",
    "SEL WORD": f"{{t: '{SELECT}', h: 'Word', s: 'slct'}}",
    "LEFT": f"{{t: '{LEFT}', h: '', s: ''}}",
    "RIGHT": f"{{t: '{RIGHT}', h: '', s: ''}}",
    "DOWN": f"{{t: '{DOWN}', h: '', s: ''}}",
    "UP": f"{{t: '{UP}', h: '', s: ''}}",
    "LYR LOCK": f"{{t: '{LOCK}', h: 'Layer', s: ''}}",
    "CKC(WORD JUMPL)": f"{{t: '{JUMP_LEFT}', h: 'Word', s: 'Jump'}}",
    "CKC(WORD JUMPR)": f"{{t: '{JUMP_RIGHT}', h: 'Word', s: 'Jump'}}",
    "CKC(LINE JUMPL)": f"{{t: '{JUMP_LEFT}', h: 'Line', s: 'Jump'}}",
    "CKC(LINE JUMPR)": f"{{t: '{JUMP_RIGHT}', h: 'Line', s: 'Jump'}}",
    "CKC(TASK MNGR)": f"{{t: 'Task', h: 'Manager', s: ''}}",
    "Ctl+Sft+ TAB": f"{{t: '{PREVIOUS}', h: 'Tab', s: ''}}",
    "Ctl+ TAB": f"{{t: '{NEXT}', h: 'Tab', s: ''}}",
    # SYMBOLS 1
    "_, '-'": "{t: '_', h: 'underscore', s: ''}, {t: '-', h: 'dash', s: ''}",
    "CKC(EURO)": "{t: '€', h: '', s: ''}",
    # SYMBOLS 2
    "CAPS": f"{{t: '{CAPS_LOCK}', h: '', s: ''}}",
    "CW TOGG": f"{{t: '{CAPS_LOCK}', h: 'Word', s: ''}}",
    "CKC(CMD REDO)": f"{{t: 'REDO', h: '', s: ''}}",
    "CKC(CMD UNDO)": f"{{t: 'UNDO', h: '', s: ''}}",
    "DF(GRPT)": f"{{t: '{LAYER}', h: 'Graphite', s: ''}}",
    "DF(ISRT)": f"{{t: '{LAYER}', h: 'ISRT', s: ''}}",
    "LSFT": f"{{t: '{SHIFT}', h: '', s: ''}}",
    # ACCENTS
    "CKC(E CIRC)": f"{{t: 'Ê', h: '', s: ''}}",
    "CKC(U GRAVE)": f"{{t: 'Ù', h: '', s: ''}}",
    "CKC(I CIRC)": f"{{t: 'Î', h: '', s: ''}}",
    "CKC(I TREMA)": f"{{t: 'Ï', h: '', s: ''}}",
    "CKC(E AIGU)": f"{{t: 'É', h: '', s: ''}}",
    "CKC(E GRAVE)": f"{{t: 'È', h: '', s: ''}}",
    "CKC(A GRAVE)": f"{{t: 'À', h: '', s: ''}}",
    "CKC(O CIRC)": f"{{t: 'Ô', h: '', s: ''}}",
    "CKC(C CEDILLE)": f"{{t: 'Ç', h: '', s: ''}}",
    "CKC(U CIRC)": f"{{t: 'Û', h: '', s: ''}}",
    "CKC(A CIRC)": f"{{t: 'Â', h: '', s: ''}}",
    # NUMPAD
    "P0": f"{{t: '0', h: '', s: ''}}",
    "P1": f"{{t: '1', h: '', s: ''}}",
    "P2": f"{{t: '2', h: '', s: ''}}",
    "P3": f"{{t: '3', h: '', s: ''}}",
    "P4": f"{{t: '4', h: '', s: ''}}",
    "P5": f"{{t: '5', h: '', s: ''}}",
    "P6": f"{{t: '6', h: '', s: ''}}",
    "P7": f"{{t: '7', h: '', s: ''}}",
    "P8": f"{{t: '8', h: '', s: ''}}",
    "P9": f"{{t: '9', h: '', s: ''}}",
    "PAST": f"{{t: '*', h: '', s: ''}}",
    "PSLS": f"{{t: '/', h: '', s: ''}}",
    "PPLS": f"{{t: '+', h: '', s: ''}}",
    "PMNS": f"{{t: '-', h: 'minus', s: ''}}",
    # MEDIA
    "MNXT": f"{{t: '{NEXT}', h: 'Track', s: ''}}",
    "MPLY": f"{{t: '{PLAY}', h: 'Track', s: ''}}",
    "VOLU": f"{{t: '{UP}', h: 'Volume', s: ''}}",
    "VOLD": f"{{t: '{DOWN}', h: 'Volume', s: ''}}",
    "RGB MOD": f"{{t: '{LEFT}', h: 'Mod', s: 'RGB'}}",
    "RGB RMOD": f"{{t: '{RIGHT}', h: 'Mod', s: 'RGB'}}",
    "RGB SAI": f"{{t: '{UP}', h: 'Sat', s: 'Sat'}}",
    "RGB SAD": f"{{t: '{DOWN}', h: 'Sat', s: 'RGB'}}",
    "RGB VAI": f"{{t: '{UP}', h: 'Brightness', s: 'RGB'}}",
    "RGB VAD": f"{{t: '{DOWN}', h: 'Brightness', s: 'RGB'}}",
    "RGB HUI": f"{{t: '{UP}', h: 'HUE', s: 'RGB'}}",
    "RGB HUD": f"{{t: '{DOWN}', h: 'HUE', s: 'RGB'}}",
    "RGB SPI": f"{{t: '{UP}', h: 'Speed', s: 'RGB'}}",
    "RGB SPD": f"{{t: '{DOWN}', h: 'Speed', s: 'RGB'}}",
    "DEL": f"{{t: '{DELETE}', h: 'char', s: 'del'}}", # WARNING: Keep after all other DELETE actions
    }

def replace(content):
    for i, line in enumerate(content):
        for old, new in replacements.items():
            line = line.replace(old, new)
        content[i] = line

    return content

with open(RAW_FILEPATH, 'r') as raw_file:
    content = raw_file.readlines()
    content = replace(content)

    with open(FIXED_FILEPATH, 'w') as file:
        file.write("".join(content))
