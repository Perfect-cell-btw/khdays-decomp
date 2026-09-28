/* Shop state: refreshes the panel; moves to the selection tick once the fade-out ends. */

extern int Ov026_FadeOutStep(void);
extern void Ov026_RefreshPanelDisplay(void);
extern void Ov026_SelectionTick(void);
void *Ov026_ShopFadeOutThenSelection(void)
{
    void *result;
    if (Ov026_FadeOutStep() != 0) {
        result = Ov026_SelectionTick;
    } else {
        result = 0;
    }
    Ov026_RefreshPanelDisplay();
    return result;
}
