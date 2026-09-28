/* Adjusts an item's count and updates its list row (and the inventory row outside the shop). */

extern int Ov025_FindListObjectByKey();
extern void Ov025_RefreshInventoryRow();

void Ov025_AdjustAndSyncSlot(int arg0, int arg1, char arg2) {
    int base = arg0 + 0x1bf0;
    int t = *(unsigned char *)(base + arg1);
    *(unsigned char *)(base + arg1) = t + arg2;
    int *p = (int *)Ov025_FindListObjectByKey(arg0, 0, arg1);
    if (p == 0) return;
    *(unsigned char *)((int)p + 5) = *(unsigned char *)(base + arg1);
    if (*(int *)(arg0 + 8) != 0) return;
    Ov025_RefreshInventoryRow(arg0, *(int *)(*p + 0x14));
}
