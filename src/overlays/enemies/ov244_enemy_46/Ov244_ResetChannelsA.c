/* Clears bit 1 of the sub-object's flag word at +0x5c, rewrites its four state channels
 * (0, 2, 1, 4) to (0, 0), closes the update, clears the +8 word and re-arms 020cec88. */
extern void SetSubitemState(void *sub, int channel, short value, int flag);
extern void RefreshObjectCallbacks(void *sub, int a);
extern void SetIndexedSlot(char *self, int a, void *cb);
extern void Ov244_PounceRideTick(int);

void Ov244_ResetChannelsA(char *self) {
    char *ctx = *(char **)(self + 4);
    *(int *)(*(char **)ctx + 0x5c) &= ~2;
    SetSubitemState(*(void **)ctx, 0, 0, 0);
    SetSubitemState(*(void **)ctx, 2, 0, 0);
    SetSubitemState(*(void **)ctx, 1, 0, 0);
    SetSubitemState(*(void **)ctx, 4, 0, 0);
    RefreshObjectCallbacks(*(void **)ctx, 0);
    *(int *)(ctx + 8) = 0;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), (void *)Ov244_PounceRideTick);
}
