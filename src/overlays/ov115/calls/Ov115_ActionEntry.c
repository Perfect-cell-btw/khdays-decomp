/* Action entry of the ov115 enemy (and its byte-identical twins): clears bit 1 of the actor's
 * +0x5c flag word, resets state channels 0, 2, 4 and 1 to zero, closes the update, zeroes the
 * +0x18 timer and +0x1c phase of the context and hands off to the attack tick. */
extern void SetSubitemState(void *sub, int channel, short value, int flag);
extern void RefreshObjectCallbacks(void *sub, int a);
extern void SetIndexedSlot(char *self, int a, void *cb);
extern void Ov115_DropStrikeTick(int);

void Ov115_ActionEntry(char *self) {
    char *ctx = *(char **)(self + 4);
    *(int *)(*(char **)ctx + 0x5c) &= ~2;
    SetSubitemState(*(void **)ctx, 0, 0, 0);
    SetSubitemState(*(void **)ctx, 2, 0, 0);
    SetSubitemState(*(void **)ctx, 4, 0, 0);
    SetSubitemState(*(void **)ctx, 1, 0, 0);
    RefreshObjectCallbacks(*(void **)ctx, 0);
    *(int *)(ctx + 0x18) = 0;
    *(unsigned char *)(ctx + 0x1c) = 0;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), (void *)Ov115_DropStrikeTick);
}
