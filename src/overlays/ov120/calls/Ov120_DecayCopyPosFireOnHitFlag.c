struct v3 { int x, y, z; };
struct bit0 { unsigned char b : 1; };
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov120_AiStep_QueueAction2OnFlag48Clear_2(void);

void Ov120_DecayCopyPosFireOnHitFlag(int *node) {
    int *state = (int *)node[1];
    state[0xb] -= 0x100;
    *(struct v3 *)((char *)state + 0x1c) = *(struct v3 *)((char *)state + 0x28);
    if (!((struct bit0 *)(*state + 0x17a))->b) return;
    Ov107_PostTagUpdate(*state, 6, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov120_AiStep_QueueAction2OnFlag48Clear_2);
}
