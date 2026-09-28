extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov141_ConfigHw60CopyVec3ConstThenAdvance(void);
extern void Ov141_StepSlamProbe(void);
void Ov141_dispatchByStatusByte(int *node) {
    int *state = (int *)node[1];
    signed char c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = c;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov141_ConfigHw60CopyVec3ConstThenAdvance);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov141_StepSlamProbe);
            break;
        }
        *(signed char *)(*state + 0x1c7) = 0xff;
    }
}
