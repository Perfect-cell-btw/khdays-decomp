/* Finds an entry by id in the menu's mission list. Returns the object, or NULL. */

extern int Ov008_GetMenuContext(void);
extern void *Ov008_FindListObjectById(int, int);
void *Ov008_GetNextMissionEntry_5(int value)
{
    return Ov008_FindListObjectById(Ov008_GetMenuContext() + 0x13fc, value);
}
