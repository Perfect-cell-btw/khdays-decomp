extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov168_ConfigHw60CopyVec3ConstToCThenAdvance(void);
extern void Ov168_BeginDash(void);
void Ov168_dispatchByStatusByteReset(int *node) {
    int *state = (int *)node[1];
    signed char c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = c;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov168_ConfigHw60CopyVec3ConstToCThenAdvance);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov168_BeginDash);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = 0xff;
}
