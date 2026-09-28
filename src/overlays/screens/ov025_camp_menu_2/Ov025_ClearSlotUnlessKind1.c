extern int Ov025_GetBlock4a80(void);
extern void Ov025_GetTouchSample(int block, unsigned short *out);
/* Query the current block's descriptor; unless its kind word reads 1, clear the caller's slot. */
void Ov025_ClearSlotUnlessKind1(int obj) {
    unsigned short desc[4];
    Ov025_GetTouchSample(Ov025_GetBlock4a80(), desc);
    if (desc[2] != 1) {
        *(int *)(obj + 0x34) = 0;
    }
}
