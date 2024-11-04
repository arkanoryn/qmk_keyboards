from functools import partial

def lines(*args: str) -> str:
    """Create a multi-line string based on input lines."""
    return "\n".join([*args])

__HEADER_WARNING = """/*
**  /!\\ This file is generated with the script `{script_path}/{main_file}`
**  Do NOT manually modify or create files in the `{generated_folder}` folder.
**  Prefer re-running the script: `python {main_file}`
**  ex:
**
**       $> python {main_file}
**
**  Copyright {year} Pierre-Nicolas "Ark'Anoryn" Sormani <arkanoryn@gmail.com>
**  SPDX-License-Identifier: GPL-2.0-or-later
**
*/
"""

_HEADER = partial(__HEADER_WARNING.format, year="2024", main_file="main.py", generated_folder="generated/", script_path="scripts")

HEADER_CFILE = _HEADER()
HEADER_HFILE = f"{HEADER_CFILE}\n#pragma once\n"
