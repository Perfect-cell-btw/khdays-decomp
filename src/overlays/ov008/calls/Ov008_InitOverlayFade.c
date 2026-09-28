/* Ov008_InitOverlayFade -- start the menu's close/collapse slide, ov008.
 * Unless already closed (Ov008_IsEntryBusyOrInactive set), kicks a scroll animation on the panel
 * (rec+0x10) from rec+0x2c to -0x10000 over 100 units, commits it, raises the closed flag
 * (rec+0x1f4=1) and sets the panel state to closing (rec+0x1f8=2). */
extern int  Ov008_GetPageB(void);
extern int  Ov008_IsEntryBusyOrInactive(void);
extern void Tween_Configure(unsigned int *anim, int a, unsigned int from, int to, int dur);
extern void Tween_Start(int anim);

void Ov008_InitOverlayFade(void) {
    int rec = Ov008_GetPageB();
    if (Ov008_IsEntryBusyOrInactive() == 0) {
        Tween_Configure((unsigned int *)(rec + 0x10), 0, *(unsigned int *)(rec + 0x2c), -0x10000, 100);
        Tween_Start(rec + 0x10);
        *(int *)(rec + 0x1f4) = 1;
        *(int *)(rec + 0x1f8) = 2;
    }
}
