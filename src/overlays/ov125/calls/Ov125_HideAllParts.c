/* Set bit 1 in the +0x5c flags of each of the five child pointers (+4..+0x14) and dispatch. */
extern int SetIndexedSlot(int a, int b, void *handler);
void Ov125_HideAllParts(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(*(int *)(child + 4) + 0x5c) |= 2;
    *(int *)(*(int *)(child + 8) + 0x5c) |= 2;
    *(int *)(*(int *)(child + 0xc) + 0x5c) |= 2;
    *(int *)(*(int *)(child + 0x10) + 0x5c) |= 2;
    *(int *)(*(int *)(child + 0x14) + 0x5c) |= 2;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
