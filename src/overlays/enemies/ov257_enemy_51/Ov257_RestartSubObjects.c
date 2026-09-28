/* Helper tick of the ov257 enemy: unless its owner's kind (+0x1c6) is 0xc, the owner's four
 * sub-objects (+0x3a4 array) restart channel 2 (mode 2) and the slot hands over to
 * Ov257_AdvanceIfUnlocked. The array is indexed as ((int *)owner)[0xe9 + i] (0xe9 * 4 == 0x3a4) so
 * mwcc emits the ROM's `add base,i<<2; ldr [.,#0x3a4]` addressing. */
extern int SetSubitemState(int obj, int slot, int a, int b);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov257_AdvanceIfUnlocked(int *node);

void Ov257_RestartSubObjects(int *node)
{
    int *h = (int *)node[1];
    int i;

    if (*(signed char *)(h[0] + 0x1c6) == 0xc) {
        return;
    }
    for (i = 0; i < 4; i++) {
        SetSubitemState(((int *)h[0])[0xe9 + i], 2, 2, 0);
    }
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov257_AdvanceIfUnlocked);
}
