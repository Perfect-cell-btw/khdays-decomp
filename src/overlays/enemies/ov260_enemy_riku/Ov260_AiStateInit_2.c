/* Point +0x18 at obj+0xb0, reset the sub-state (+0x1c6=0, +0x1c7=-1), clear bit0 of the hw60 hi
 * byte and +0x1ae, then hand off across the Ov260_dispatchByStatusByte_2 / Ov260_HaltEntry_2 / Ov260_Item_ApplyOrientation trio. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov260_dispatchByStatusByte_2(int);
extern int Ov260_HaltEntry_2(int);
extern int Ov260_Item_ApplyOrientation(int);
struct hw60 { unsigned short lo : 8, hi : 8; };
void Ov260_AiStateInit_2(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x18) = *(int *)owner + 0xb0;
    *(unsigned char *)(*(int *)owner + 0x1c6) = 0;
    *(signed char *)(*(int *)owner + 0x1c7) = -1;
    ((struct hw60 *)(*(int *)owner + 0x60))->hi &= ~1;
    *(unsigned short *)(*(int *)owner + 0x1ae) &= ~1;
    SetIndexedSlot(param_1, 0, (void *)&Ov260_dispatchByStatusByte_2);
    SetIndexedSlot(param_1, 1, (void *)&Ov260_HaltEntry_2);
    SetIndexedSlot(param_1, 2, (void *)&Ov260_Item_ApplyOrientation);
}
