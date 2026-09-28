/* Ov008_ConfigureTagBySign -- set a mission list row's enabled/value state, ov008.
 * Finds the row widget (Ov008_FindEntryById) for tag param_1; a non-negative param_2 enables it
 * (Ov008_SetEntrySlotsVisible(...,1)) and pushes the value (Ov008_ReleaseTwoSlotsEx), a negative param_2
 * disables it (Ov008_SetEntrySlotsVisible(...,0)). */
extern int  Ov008_GetContext(void);
extern int  Ov008_FindEntryById(int list, int tag);
extern void Ov008_SetEntrySlotsVisible(int list, int row, int enabled);
extern void Ov008_ReleaseTwoSlotsEx(int list, int row, int value);

void Ov008_ConfigureTagBySign(int tag, unsigned int value) {
    int list = Ov008_GetContext();
    int row = Ov008_FindEntryById(list, tag);
    if ((int)value >= 0) {
        Ov008_SetEntrySlotsVisible(list, row, 1);
        Ov008_ReleaseTwoSlotsEx(list, row, value & 0xffff);
    } else {
        Ov008_SetEntrySlotsVisible(list, row, 0);
    }
}
