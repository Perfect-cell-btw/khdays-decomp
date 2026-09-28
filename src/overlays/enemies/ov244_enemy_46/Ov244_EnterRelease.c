/* Release entry: clears bit 1 of the +4 child's +0x5c, installs the 020ced6c handler at its
 * +0x6c and back-links the state at its +0x84, binds its channels 0 / 4 / 1 / 2 with (0, 0),
 * re-inits it, clears the +8 word, installs 020ceee4 on slot 2 and moves the node to 020ceee8. */
extern void SetSubitemState(int obj, int slot, int a, int b);
extern void RefreshObjectCallbacks(int obj, int a);
extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov244_RenderAtOwnerNode(void);
extern void Ov244_AiSlot2NoOp(void);
extern void Ov244_WaitRigIdle(void);

void Ov244_EnterRelease(int param_1) {
    int *node = *(int **)(param_1 + 4);
    *(int *)(node[1] + 0x5c) &= ~2;
    *(void **)(node[1] + 0x6c) = (void *)&Ov244_RenderAtOwnerNode;
    *(int **)(node[1] + 0x84) = node;
    SetSubitemState(node[1], 0, 0, 0);
    SetSubitemState(node[1], 4, 0, 0);
    SetSubitemState(node[1], 1, 0, 0);
    SetSubitemState(node[1], 2, 0, 0);
    RefreshObjectCallbacks(node[1], 0);
    node[2] = 0;
    SetIndexedSlot(param_1, 2, &Ov244_AiSlot2NoOp);
    SetIndexedSlot(param_1, *(signed char *)((char *)param_1 + 0x20), &Ov244_WaitRigIdle);
}
