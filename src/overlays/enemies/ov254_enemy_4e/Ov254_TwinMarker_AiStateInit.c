/* Reset the sub-state (+0x1c6=0, +0x1c7=-1), clear bit0 of both the hw60 hi byte and +0x1ae,
 * then hand off to the 020d56ac / 020d5790 pair. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov254_HelperCMoveDispatch(int);
extern int Ov254_TwinMarker_AiEnterIdle(int);
struct hw60 { unsigned short lo : 8, hi : 8; };
void Ov254_TwinMarker_AiStateInit(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(unsigned char *)(*(int *)owner + 0x1c6) = 0;
    *(signed char *)(*(int *)owner + 0x1c7) = -1;
    ((struct hw60 *)(*(int *)owner + 0x60))->hi &= ~1;
    *(unsigned short *)(*(int *)owner + 0x1ae) &= ~1;
    SetIndexedSlot(param_1, 0, (void *)&Ov254_HelperCMoveDispatch);
    SetIndexedSlot(param_1, 1, (void *)&Ov254_TwinMarker_AiEnterIdle);
}
