/* Resolve the argument to a slot index with Ov025_MapCodeToSlotIndex and set that slot's bit in the
 * mask byte at +0x963c of the ov025 menu context. A -1 (not found) result is ignored. */

extern int Ov025_MapCodeToSlotIndex();
extern int data_ov025_020b5744;

void Ov025_MarkSlotUsed(int arg0) {
    int r = Ov025_MapCodeToSlotIndex(arg0);
    if (r == -1) {
        return;
    }
    *(unsigned char *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x963c) |= 1 << r;
}
