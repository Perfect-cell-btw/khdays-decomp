/* Notify ObjNode_InitFromDesc, then set status bit 2 (mask 4) at param_1+0x4a7c. */
extern void ObjNode_InitFromDesc(int obj);
void Ov009_InitFromDescAndMark(int param_1) {
    ObjNode_InitFromDesc(param_1);
    *(int *)(param_1 + 0x4a7c) |= 4;
}
