/* Ov275_WaitRigIdle -- state step of the ov274-family enemy: once the rig's +0xad busy byte is clear,
 * sets sub-items 0, 1, 2 and 4 to (1, 1) and moves the node's slot on to 020d27c8. */
extern void SetSubitemState(int rig, int idx, int blend, int value);
extern int SetIndexedSlot(int node, int slot, void *handler);
extern void Ov275_WaitNotStaggered(int node);

void Ov275_WaitRigIdle(int node)
{
    int child = *(int *)(node + 4);

    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) == 0) {
        SetSubitemState(*(int *)(child + 4), 0, 1, 1);
        SetSubitemState(*(int *)(child + 4), 1, 1, 1);
        SetSubitemState(*(int *)(child + 4), 2, 1, 1);
        SetSubitemState(*(int *)(child + 4), 4, 1, 1);
        SetIndexedSlot(node, *(signed char *)(node + 0x20), (void *)&Ov275_WaitNotStaggered);
        return;
    }
}
