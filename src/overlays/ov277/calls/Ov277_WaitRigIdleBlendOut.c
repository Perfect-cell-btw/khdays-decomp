/* Ov277_WaitRigIdleBlendOut -- state step: once the rig's +0xad busy byte is clear, sets sub-items
 * 0, 2, 4 and 1 to (2, 0), refreshes the rig's callbacks and moves the node's slot on to 020ce7c0. */
extern void SetSubitemState(int rig, int idx, int blend, int value);
extern void RefreshObjectCallbacks(int rig, int value);
extern int SetIndexedSlot(int node, int slot, void *handler);
extern void Ov277_FinishIfOwnerIdle(int node);

void Ov277_WaitRigIdleBlendOut(int node)
{
    int child = *(int *)(node + 4);

    if (*(unsigned char *)(*(int *)child + 0xad) == 0) {
        SetSubitemState(*(int *)child, 0, 2, 0);
        SetSubitemState(*(int *)child, 2, 2, 0);
        SetSubitemState(*(int *)child, 4, 2, 0);
        SetSubitemState(*(int *)child, 1, 2, 0);
        RefreshObjectCallbacks(*(int *)child, 0);
        SetIndexedSlot(node, *(signed char *)(node + 0x20), (void *)&Ov277_FinishIfOwnerIdle);
        return;
    }
}
