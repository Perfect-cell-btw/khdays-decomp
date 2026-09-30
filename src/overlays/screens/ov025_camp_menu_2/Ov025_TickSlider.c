/* Per-frame nudge of a two-state slider (field +8): state 1 slides -8 while phase bit 6 holds,
 * state 2 slides +8 while phase bit 7 holds; on release or any other state, reset to 0. */

extern void Ov025_ScrollMissionList(int obj, int delta);
extern unsigned short gPadHeld;

void Ov025_TickSlider(int param_1) {
    switch (*(int *)(param_1 + 8)) {
    case 1:
        if (gPadHeld & 0x40) {
            Ov025_ScrollMissionList(param_1, -8);
            return;
        }
        *(int *)(param_1 + 8) = 0;
        return;
    case 2:
        if (gPadHeld & 0x80) {
            Ov025_ScrollMissionList(param_1, 8);
            return;
        }
        *(int *)(param_1 + 8) = 0;
        return;
    default:
        *(int *)(param_1 + 8) = 0;
    }
}
