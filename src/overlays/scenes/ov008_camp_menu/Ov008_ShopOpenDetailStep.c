/* Shop state: opens the detail panel, refreshes, and moves to the detail confirm tick. */

extern void Ov008_OpenShopDetailPanel(void);
extern void Ov008_RefreshPanelDisplay(void);
extern void Ov008_ShopDetailConfirmTick(void);
void *Ov008_ShopOpenDetailStep(void)
{
    Ov008_OpenShopDetailPanel();
    Ov008_RefreshPanelDisplay();
    return Ov008_ShopDetailConfirmTick;
}
