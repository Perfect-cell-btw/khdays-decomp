/* Kick ObjNode_InitFromDesc for param_1, then set status bit 2 (0x4) at param_1+0x4a7c. */
extern void ObjNode_InitFromDesc(int obj, int *desc);

void Ov008_InitFromDescAndMark(int param_1, int *desc) {
    ObjNode_InitFromDesc(param_1, desc);
    *(int *)(param_1 + 0x4a7c) |= 4;
}
