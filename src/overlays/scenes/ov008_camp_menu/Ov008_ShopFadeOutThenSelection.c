/* Shop state: refreshes the panel; moves to the selection tick once the fade-out ends. */

extern int Ov008_FadeOutStep(void);
extern void Ov008_RefreshPanelDisplay(void);
extern void Ov008_SelectionTick(void);
void *Ov008_ShopFadeOutThenSelection(void)
{
    void *result;
    if (Ov008_FadeOutStep() != 0) {
        result = Ov008_SelectionTick;
    } else {
        result = 0;
    }
    Ov008_RefreshPanelDisplay();
    return result;
}
