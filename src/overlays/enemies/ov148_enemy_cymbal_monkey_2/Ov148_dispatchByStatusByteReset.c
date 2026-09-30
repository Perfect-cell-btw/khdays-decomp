/* State dispatcher: when an action is pending (+0x1c7 not -1) makes it current (+0x1c6) and
 * installs the step that starts it; then marks nothing pending. */

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov148_ResetPoseAndFlags(void);
extern void Ov148_ResetOrientationAndAdvance(void);
void Ov148_dispatchByStatusByteReset(int *node) {
    int *state = (int *)node[1];
    signed char c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = c;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov148_ResetPoseAndFlags);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov148_ResetOrientationAndAdvance);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = 0xff;
}
