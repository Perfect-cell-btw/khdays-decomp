extern int Ov008_GetMenuContext(void);
extern void Ov008_FindListObjectById(int, int);
void Ov008_GetNextMissionEntry_5(int value)
{
    Ov008_FindListObjectById(Ov008_GetMenuContext() + 0x13fc, value);
}
