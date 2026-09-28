/* Returns the record of an entry of the menu's mission list. */

extern int Ov008_GetMenuContext(void);
extern int Ov008_VarTable_GetRecordOfEntry(int, int);
int Ov008_GetNextMissionEntry_3(int value)
{
    return Ov008_VarTable_GetRecordOfEntry(Ov008_GetMenuContext() + 0x13fc, value);
}
