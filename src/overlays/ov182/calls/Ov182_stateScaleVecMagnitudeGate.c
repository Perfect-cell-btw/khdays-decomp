struct v3 { int a, b, c; };
extern void ScaleVec3Fx12();
extern int VEC_Mag();
extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov182_AiQueue2OnFlagClear(void);
void Ov182_stateScaleVecMagnitudeGate(int *node) {
    int *state = (int *)node[1];
    *(struct v3 *)(state + 0x15) = *(struct v3 *)(state + 0x18);
    ScaleVec3Fx12(0xb00, state + 0x18, state + 0x18);
    if (VEC_Mag(state + 0x18) >= 0x10) return;
    Ov107_PostTagUpdate(*state, 10, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov182_AiQueue2OnFlagClear);
}
