/* Ov009_ConfigureTagBySign -- set a mission list row's enabled/value state, ov008.
 * Finds the row widget (Ov009_FindEntryById) for tag param_1; a non-negative param_2 enables it
 * (Ov009_SetEntrySlotsVisible(...,1)) and pushes the value (Ov009_ReleaseTwoSlotsEx_2), a negative param_2
 * disables it (Ov009_SetEntrySlotsVisible(...,0)). */
extern int  Ov009_GetContext(void);
extern int  Ov009_FindEntryById(int list, int tag);
extern void Ov009_SetEntrySlotsVisible(int list, int row, int enabled);
extern void Ov009_ReleaseTwoSlotsEx_2(int list, int row, int value);

void Ov009_ConfigureTagBySign(int tag, unsigned int value) {
    int list = Ov009_GetContext();
    int row = Ov009_FindEntryById(list, tag);
    if ((int)value >= 0) {
        Ov009_SetEntrySlotsVisible(list, row, 1);
        Ov009_ReleaseTwoSlotsEx_2(list, row, value & 0xffff);
    } else {
        Ov009_SetEntrySlotsVisible(list, row, 0);
    }
}
