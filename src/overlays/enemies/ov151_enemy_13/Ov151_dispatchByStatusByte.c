extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov151_ClearAndSetNodeFlags(void);
extern void Ov151_ShotLaunch(void);
void Ov151_dispatchByStatusByte(int *node) {
    int *state = (int *)node[1];
    signed char c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        *(signed char *)(*state + 0x1c6) = c;
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov151_ClearAndSetNodeFlags);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov151_ShotLaunch);
            break;
        }
        *(signed char *)(*state + 0x1c7) = 0xff;
    }
}
