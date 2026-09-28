extern void Ov026_OpenShopDetailPanel(void);
extern void Ov026_RefreshPanelDisplay(void);
extern void Ov026_ShopDetailConfirmTick(void);
void *Ov026_ShopOpenDetailStep(void)
{
    Ov026_OpenShopDetailPanel();
    Ov026_RefreshPanelDisplay();
    return Ov026_ShopDetailConfirmTick;
}
