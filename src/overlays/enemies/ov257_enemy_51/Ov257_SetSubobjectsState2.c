extern int SetSubitemState(int obj, int slot, int a, int b);
extern int SetIndexedSlot(int self, int idx, void *handler);
extern void Ov257_RestartSubObjects(int self);

/* Reaction: unless the first sub-object is locked (arr[0]+0xaf), push all four sub-objects
 * into subitem state 2 (a=1,b=1), then re-arm the slot with follow-up 020d2c8c.
 * node=*(ReactionAiNode**)(self+4); *node=pActor. The sub-object pointer array lives at
 * pActor+0x3a4, so ((int*)pActor)[i + 0xe9] is subobjects[i] (0xe9*4 == 0x3a4) -- written this
 * way so mwcc emits `add base,i<<2; ldr [.,#0x3a4]` (the ROM's addressing) instead of hoisting
 * the base or strength-reducing to a walking pointer. */
void Ov257_SetSubobjectsState2(int self) {
    int *node = *(int **)(self + 4);
    int i;
    if (*(unsigned char *)(((int *)*node)[0xe9] + 0xaf) != 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        SetSubitemState(((int *)*node)[i + 0xe9], 2, 1, 1);
    }
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov257_RestartSubObjects);
}
