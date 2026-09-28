/* Ov244_WaitRigIdle -- state step of the ov274-family enemy: once the rig's +0xad busy byte is clear,
 * sets sub-items 0, 4, 1 and 2 to (1, 1) and moves the node's slot on to 020cef68. */
extern void SetSubitemState(int rig, int idx, int blend, int value);
extern int SetIndexedSlot(int node, int slot, void *handler);
extern void Ov244_WaitFlag420Bit4(int node);

void Ov244_WaitRigIdle(int node)
{
    int child = *(int *)(node + 4);

    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) == 0) {
        SetSubitemState(*(int *)(child + 4), 0, 1, 1);
        SetSubitemState(*(int *)(child + 4), 4, 1, 1);
        SetSubitemState(*(int *)(child + 4), 1, 1, 1);
        SetSubitemState(*(int *)(child + 4), 2, 1, 1);
        SetIndexedSlot(node, *(signed char *)(node + 0x20), (void *)&Ov244_WaitFlag420Bit4);
        return;
    }
}
