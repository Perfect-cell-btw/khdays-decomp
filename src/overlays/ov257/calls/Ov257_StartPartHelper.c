/* Start tick of the ov257 part helper: the owner's four sub-objects (+0x3a4 array) are shown (bit
 * 1 of +0x5c cleared) and restart channel 2, and slot 1 gets Ov257_SetSubobjectsState2. The array is
 * indexed as ((int *)owner)[0xe9 + i] (0xe9 * 4 == 0x3a4) for the ROM's addressing. */
extern int SetSubitemState(int obj, int slot, int a, int b);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov257_SetSubobjectsState2(int *node);

void Ov257_StartPartHelper(int *node)
{
    int *h = (int *)node[1];
    int i;

    for (i = 0; i < 4; i++) {
        *(int *)(((int *)h[0])[0xe9 + i] + 0x5c) &= ~2;
        SetSubitemState(((int *)h[0])[0xe9 + i], 2, 0, 0);
    }
    SetIndexedSlot(node, 1, (void *)Ov257_SetSubobjectsState2);
}
