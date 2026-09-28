extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov198_ResetPoseAndFlags(void);
extern void Ov198_ResetOrientationAndAdvance(void);
void Ov198_dispatchByStatusByteReset(int *node) {
    int *state = (int *)node[1];
    signed char c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = c;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov198_ResetPoseAndFlags);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov198_ResetOrientationAndAdvance);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = 0xff;
}
