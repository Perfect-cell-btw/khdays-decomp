struct v3 { int x, y, z; };
extern void ScaleVec3Fx12(int scale, void *dst, void *src);
extern void SetIndexedSlot(void *node, int idx, void *value);

void Ov219_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    *(struct v3 *)((char *)state + 0x24) = *(struct v3 *)((char *)state + 0x30);
    ScaleVec3Fx12(0xb00, (char *)state + 0x30, (char *)state + 0x30);
    if (*(unsigned char *)(state[1] + 0xad) != 0) return;
    *(signed char *)(*state + 0x1c7) = 7;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
