/* When page B's mission is selected and ready, applies its widgets and confirms it. */

extern int Ov025_GetPageB();
extern void Ov025_ApplyModeWidgets();
extern void Ov025_MissionList_Confirm();

void Ov025_StepIfReadyAlt(void) {
    unsigned int *x = (unsigned int *)Ov025_GetPageB();
    if (x[0x10] != 0 && x[0x11] == 0) return;
    if (x[0x13e] == 0) return;
    if (x[0x13f] == 0) Ov025_ApplyModeWidgets((int)x, 1);
    Ov025_MissionList_Confirm(x);
}
