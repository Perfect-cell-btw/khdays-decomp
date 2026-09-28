extern int Ov008_FadeInStep(void);
extern void func_020362ec(void *image);
extern void Ov008_UpdateTouchState(void);
extern void Ov008_RefreshPanelDisplay(void);
extern void Ov008_ShopConfirmPurchase(void);
extern char *data_ov008_02090fac[];

void *Ov008_Shop_WaitDialogClose(void)
{
    void *result;

    if (Ov008_FadeInStep() != 0) {
        result = Ov008_ShopConfirmPurchase;
    } else {
        result = 0;
    }

    func_020362ec(data_ov008_02090fac[0] + 0xc0fc);
    Ov008_UpdateTouchState();
    Ov008_RefreshPanelDisplay();

    return result;
}
