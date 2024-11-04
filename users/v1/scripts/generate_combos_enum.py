        # for index, combo in enumerate(combos):
        #     name = "{prefix}_{combo_name}".format(prefix=prefix, combo_name=combo[NAME_POS])
        #     keys = []
        #     for i, key in enumerate(combo):
        #         if i > CAN_CYCLE_POS:
        #             keys.append("{prefix}_{key}".format(prefix=prefix, key=key))

        #     if combo[CAN_CYCLE_POS] == "circle":
        #         cycles_e.append(("{name} = 0".format(name=combo[NAME_POS]), index)) if cycles_e == [] else cycles_e.append((combo[NAME_POS], index))

            # combos_e.append("{name} = 0".format(name=name))if combos_e == [] else combos_e.append(name)
            # combos_prog.append("const uint16_t PROGMEM {name}_COMBO[] = {{{keys}, COMBO_END}};".format(name=name, keys=", ".join(keys)))
            # combos_t.append("[{name}] = COMBO_ACTION({name}_COMBO)".format(name=name))
            # combos_cmds.append("[{name}] = \"{cmd}\"".format(name=name, cmd=combo[STR_POS]))
