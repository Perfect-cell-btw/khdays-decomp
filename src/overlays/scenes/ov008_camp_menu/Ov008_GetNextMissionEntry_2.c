/* Returns the Nth zero-count entry of the menu's mission list. */

extern int Ov008_GetMenuContext(void);
extern void Ov008_NthZeroCountNode(int, int);
void Ov008_GetNextMissionEntry_2(int value)
{
    Ov008_NthZeroCountNode(Ov008_GetMenuContext() + 0x13fc, value);
}
