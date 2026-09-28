/* Steps page B's slide while its entry is busy. */

extern int Ov008_IsEntryBusyOrInactive(void);
extern void Ov008_StepPageBSlide(void);
void Ov008_PageB_StepSlideIfBusy(void)
{
    if (Ov008_IsEntryBusyOrInactive() != 0) {
        Ov008_StepPageBSlide();
    }
}
