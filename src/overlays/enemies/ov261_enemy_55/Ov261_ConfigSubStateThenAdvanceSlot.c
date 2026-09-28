extern int Ov261_FindGrabSlotPath(int *state, int flag);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov261_AimTick(void);

void Ov261_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    if (*(int *)(*state + 0x3a8) == 0) {
        *(signed char *)(*state + 0x1c7) = 2;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    state[0x1c] = Ov261_FindGrabSlotPath(state, *(unsigned char *)(*state + 0x3ac));
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov261_AimTick);
}
