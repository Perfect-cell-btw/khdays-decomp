extern int Ov008_FadeOutStep(void);
extern void Ov008_RefreshPanelDisplay(void);
extern void Ov008_ConfirmSelection(void);
void *Ov008_ShopFadeOutThenConfirm(void)
{
    void *result = 0;
    if (Ov008_FadeOutStep() != 0) {
        result = Ov008_ConfirmSelection;
    }
    Ov008_RefreshPanelDisplay();
    return result;
}
