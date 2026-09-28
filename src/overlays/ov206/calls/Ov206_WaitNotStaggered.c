/* Ov206_WaitNotStaggered -- state step of the ov274-family enemy: unless the owner's +0x310 state is
 * 3 or 4, sets sub-items 0, 1, 2 and 4 to (2, 0) and moves the node's slot on to 020ccdf4. */
extern void SetSubitemState(int rig, int idx, int blend, int value);
extern int SetIndexedSlot(int node, int slot, void *handler);
extern void Ov206_FinishIfSubFlagClear(int node);

void Ov206_WaitNotStaggered(int node)
{
    int child = *(int *)(node + 4);
    signed char nState = *(signed char *)(*(int *)child + 0x310);

    if (nState != 4 && nState != 3) {
        SetSubitemState(*(int *)(child + 4), 0, 2, 0);
        SetSubitemState(*(int *)(child + 4), 1, 2, 0);
        SetSubitemState(*(int *)(child + 4), 2, 2, 0);
        SetSubitemState(*(int *)(child + 4), 4, 2, 0);
        SetIndexedSlot(node, *(signed char *)(node + 0x20), (void *)&Ov206_FinishIfSubFlagClear);
        return;
    }
}
