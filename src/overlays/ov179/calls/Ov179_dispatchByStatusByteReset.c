extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov179_ToggleStanceFlags(void);
extern void Ov179_SettleEnter(void);
void Ov179_dispatchByStatusByteReset(int *node) {
    int *state = (int *)node[1];
    signed char c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = c;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov179_ToggleStanceFlags);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov179_SettleEnter);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = 0xff;
}
