/* Steps page B's slide while its entry is busy. */

extern int Ov025_IsEntryBusyOrInactive();
extern int Ov025_StepPageBSlide();

void Ov025_PageB_StepSlideIfBusy(int arg0) {
    if (Ov025_IsEntryBusyOrInactive(arg0) == 0) {
        return;
    }
    Ov025_StepPageBSlide();
}
