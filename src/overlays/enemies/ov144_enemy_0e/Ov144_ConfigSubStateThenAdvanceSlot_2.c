struct row3d4 { char _pad[0x3d4]; int f; };
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov144_CountdownTimer38ThenPose5(void);

void Ov144_ConfigSubStateThenAdvanceSlot_2(int *node) {
    int *state = (int *)node[1];
    if (*(unsigned char *)(*(int *)(*state + 0x384) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*state, 4, 1);
    state[0xe] = ((struct row3d4 *)((int *)*state + state[0x12]))->f;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov144_CountdownTimer38ThenPose5);
}
