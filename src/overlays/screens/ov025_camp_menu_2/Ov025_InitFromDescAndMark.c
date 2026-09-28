/* Inits the node from its descriptor and sets flag bit 2 (+0x4a7c). */

extern int ObjNode_InitFromDesc();

void Ov025_InitFromDescAndMark(int arg0) {
    ObjNode_InitFromDesc(arg0);
    *(int *)(arg0 + 0x4a7c) |= 4;
}
