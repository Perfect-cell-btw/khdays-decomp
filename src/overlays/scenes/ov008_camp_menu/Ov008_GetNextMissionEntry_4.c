/* Looks an entry up in the menu's mission list (func_ov008_0205665c). Returns the record, or NULL
 * when the index is out of range. */

extern int Ov008_GetMenuContext(void);
extern void *func_ov008_0205665c(int, int);
void *Ov008_GetNextMissionEntry_4(int value)
{
    return func_ov008_0205665c(Ov008_GetMenuContext() + 0x13fc, value);
}
