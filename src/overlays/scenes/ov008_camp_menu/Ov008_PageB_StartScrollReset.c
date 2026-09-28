/* Ov008_PageB_StartScrollReset -- start the menu's open/expand slide, ov008.
 * Unless already open (Ov008_IsEntryBusyOrInactive set and rec+0x1f4 clear), kicks a scroll animation on
 * the panel (rec+0x10) from rec+0x2c to 0 over 100 units, commits it, clears the closed flag
 * (rec+0x1f4) and raises the visible flag (rec+0x1f8). */
extern int  Ov008_GetPageB(void);
extern int  Ov008_IsEntryBusyOrInactive(void);
extern void Tween_Configure(unsigned int *anim, int a, unsigned int from, int to, int dur);
extern void Tween_Start(int anim);

void Ov008_PageB_StartScrollReset(void) {
    int rec = Ov008_GetPageB();
    if (Ov008_IsEntryBusyOrInactive() != 0 && *(int *)(rec + 0x1f4) == 0) {
        return;
    }
    Tween_Configure((unsigned int *)(rec + 0x10), 0, *(unsigned int *)(rec + 0x2c), 0, 100);
    Tween_Start(rec + 0x10);
    *(int *)(rec + 0x1f4) = 0;
    *(int *)(rec + 0x1f8) = 1;
}
