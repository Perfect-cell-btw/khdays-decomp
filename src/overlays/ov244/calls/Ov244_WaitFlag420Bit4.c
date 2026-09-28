/* Once bit 4 of the actor's +0x420 word is set, the +4 child's four channels (0, 4, 1, 2) are
 * bound with (2, 0) and the node moves to 020ceff0. */
struct Flags420 { int b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1; };
extern void SetSubitemState(int obj, int slot, int a, int b);
extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov244_FinishIfSubFlagClear(void);

void Ov244_WaitFlag420Bit4(int param_1) {
    int *node = *(int **)(param_1 + 4);
    if (((struct Flags420 *)(*node + 0x420))->b4 != 0) {
        SetSubitemState(node[1], 0, 2, 0);
        SetSubitemState(node[1], 4, 2, 0);
        SetSubitemState(node[1], 1, 2, 0);
        SetSubitemState(node[1], 2, 2, 0);
        SetIndexedSlot(param_1, *(signed char *)((char *)param_1 + 0x20), &Ov244_FinishIfSubFlagClear);
        return;
    }
}
