extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov170_ConfigHw60CopyVec3ConstToCThenAdvance(void);
extern void Ov170_BeginLeap(void);
void Ov170_dispatchByStatusByteReset(int *node) {
    int *state = (int *)node[1];
    signed char c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = c;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov170_ConfigHw60CopyVec3ConstToCThenAdvance);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov170_BeginLeap);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = 0xff;
}
