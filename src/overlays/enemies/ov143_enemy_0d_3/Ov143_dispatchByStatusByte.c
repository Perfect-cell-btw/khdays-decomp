/* State dispatcher: when an action is pending (+0x1c7 not -1) makes it current (+0x1c6), installs
 * the step that starts it and marks nothing pending. */

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov143_ConfigHw60CopyVec3ConstThenAdvance(void);
extern void Ov143_StepSlamProbe(void);
void Ov143_dispatchByStatusByte(int *node) {
    int *state = (int *)node[1];
    signed char c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = c;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov143_ConfigHw60CopyVec3ConstThenAdvance);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov143_StepSlamProbe);
            break;
        }
        *(signed char *)(*state + 0x1c7) = 0xff;
    }
}
