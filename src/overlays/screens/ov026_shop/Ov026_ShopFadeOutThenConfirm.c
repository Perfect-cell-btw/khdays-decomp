/* Shop state: refreshes the panel; moves to the selection confirm once the fade-out ends. */

extern int Ov026_FadeOutStep(void);
extern void Ov026_RefreshPanelDisplay(void);
extern void Ov026_ConfirmSelection(void);
void *Ov026_ShopFadeOutThenConfirm(void)
{
    void *result = 0;
    if (Ov026_FadeOutStep() != 0) {
        result = Ov026_ConfirmSelection;
    }
    Ov026_RefreshPanelDisplay();
    return result;
}
