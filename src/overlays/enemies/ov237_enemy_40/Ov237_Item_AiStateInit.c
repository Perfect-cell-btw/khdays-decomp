/* Point +8 at the linked node's +0x42c socket +0x14, reset the sub-state (+0x1c6=0, +0x1c7=-1),
 * clear bit0 of the hw60 hi byte and +0x1ae, then hand off across the 020d0e10/020d0ea0/020d0e88 trio. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov237_dispatchByStatusByteReset(int);
extern int Ov237_UnlinkEntry(int);
extern int Ov237_AiApplyMoveVector(int);
struct hw60 { unsigned short lo : 8, hi : 8; };
void Ov237_Item_AiStateInit(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 8) = *(int *)(*(int *)(*(int *)owner + 0x390) + 0x42c) + 0x14;
    *(unsigned char *)(*(int *)owner + 0x1c6) = 0;
    *(signed char *)(*(int *)owner + 0x1c7) = -1;
    ((struct hw60 *)(*(int *)owner + 0x60))->hi &= ~1;
    *(unsigned short *)(*(int *)owner + 0x1ae) &= ~1;
    SetIndexedSlot(param_1, 0, (void *)&Ov237_dispatchByStatusByteReset);
    SetIndexedSlot(param_1, 1, (void *)&Ov237_UnlinkEntry);
    SetIndexedSlot(param_1, 2, (void *)&Ov237_AiApplyMoveVector);
}
