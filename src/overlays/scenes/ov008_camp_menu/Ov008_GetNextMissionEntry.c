/* Finds the next mission entry after the value in the menu's mission list. */

extern int Ov008_GetMenuContext(void);
extern void Ov008_FindNextMissionEntry(int, int);
void Ov008_GetNextMissionEntry(int value)
{
    Ov008_FindNextMissionEntry(Ov008_GetMenuContext() + 0x13fc, value);
}
