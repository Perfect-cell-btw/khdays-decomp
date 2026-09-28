/* Reset the sub-state (+0x1c6=0, +0x1c7=-1), clear bit0 of the hw60 hi byte and +0x1ae, then hand
 * off across the 020cf034 / 020cf158 / 020cf0ac trio. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov283_dispatchByStatusByteReset(int);
extern int Ov283_ResetReactionFlags(int);
extern int Ov283_Item_AiFollowHolder(int);
struct hw60 { unsigned short lo : 8, hi : 8; };
void Ov283_Item_AiStateInit(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(unsigned char *)(*(int *)owner + 0x1c6) = 0;
    *(signed char *)(*(int *)owner + 0x1c7) = -1;
    ((struct hw60 *)(*(int *)owner + 0x60))->hi &= ~1;
    *(unsigned short *)(*(int *)owner + 0x1ae) &= ~1;
    SetIndexedSlot(param_1, 0, (void *)&Ov283_dispatchByStatusByteReset);
    SetIndexedSlot(param_1, 1, (void *)&Ov283_ResetReactionFlags);
    SetIndexedSlot(param_1, 2, (void *)&Ov283_Item_AiFollowHolder);
}
