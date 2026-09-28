/* Clears bit 1 of the sub-object's flag word at +0x5c and rewrites its four state channels
 * (0, 1, 2, 4), channel 1 taking the value stored at +8 of the context, then closes the
 * update and re-arms the follow-up. */
extern void SetSubitemState(void *sub, int channel, short value, int flag);
extern void RefreshObjectCallbacks(void *sub, int a);
extern void SetIndexedSlot(char *self, int a, void *cb);
extern void Ov278_FinishIfSubFlagClear(int);

void Ov278_ResetModelTracks(char *self) {
    char *ctx = *(char **)(self + 4);
    *(int *)(*(char **)(ctx + 4) + 0x5c) &= ~2;
    SetSubitemState(*(void **)(ctx + 4), 0, 0, 0);
    SetSubitemState(*(void **)(ctx + 4), 1, (short)*(int *)(ctx + 8), 0);
    SetSubitemState(*(void **)(ctx + 4), 2, 0, 0);
    SetSubitemState(*(void **)(ctx + 4), 4, 0, 0);
    RefreshObjectCallbacks(*(void **)(ctx + 4), 0);
    SetIndexedSlot(self, *(signed char *)(self + 0x20), (void *)Ov278_FinishIfSubFlagClear);
}
