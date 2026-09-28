extern char *data_ov008_02090fac;
extern void Ov008_OpenBuyDialog(void);
extern void Ov008_RefreshPanelDisplay(void);
extern void Ov008_Shop_WaitDialogClose(void);
extern void Ov008_ShopConfirmPurchase(void);

void (*Ov008_Shop_OpenBuy(void))(void)
{
    Ov008_OpenBuyDialog();
    Ov008_RefreshPanelDisplay();

    if (*(int *)(data_ov008_02090fac + 0xc56c) != 0) {
        return Ov008_Shop_WaitDialogClose;
    }

    return Ov008_ShopConfirmPurchase;
}
