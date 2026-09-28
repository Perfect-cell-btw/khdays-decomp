extern int Ov008_GetMenuContext(void);
extern void Ov008_VarTable_GetRecordOfEntry(int, int);
void Ov008_GetNextMissionEntry_3(int value)
{
    Ov008_VarTable_GetRecordOfEntry(Ov008_GetMenuContext() + 0x13fc, value);
}
