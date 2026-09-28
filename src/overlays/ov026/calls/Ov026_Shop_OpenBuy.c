extern char *data_ov026_02091368;
extern void Ov026_OpenBuyDialog(void);
extern void Ov026_RefreshPanelDisplay(void);
extern void Ov026_Shop_WaitDialogClose(void);
extern void Ov026_ShopConfirmPurchase(void);

void (*Ov026_Shop_OpenBuy(void))(void)
{
    Ov026_OpenBuyDialog();
    Ov026_RefreshPanelDisplay();

    if (*(int *)(data_ov026_02091368 + 0xc56c) != 0) {
        return Ov026_Shop_WaitDialogClose;
    }

    return Ov026_ShopConfirmPurchase;
}
