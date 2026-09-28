/* State: instantiates the shop class, updates the menu input and waits for the shop to close. */

extern void NNSi_FndGetCurrentRootHeap(void);
extern void InstantiateClass(void *, int);
extern void Ov008_UpdateMenuInput(void);
extern void Ov008_WaitShopClosed(void);
extern char data_ov008_02090dc4;
void *Ov008_OpenShopState(void)
{
    NNSi_FndGetCurrentRootHeap();
    InstantiateClass(&data_ov008_02090dc4, 0);
    Ov008_UpdateMenuInput();
    return Ov008_WaitShopClosed;
}
