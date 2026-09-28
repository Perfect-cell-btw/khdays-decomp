/* Inits the node from its descriptor and sets flag bit 2 (+0x4a7c). */

extern int ObjNode_InitFromDesc();

void Ov000_InitFromDescAndMark(char *p)
{
    ObjNode_InitFromDesc(p);
    *(int *)(p + 0x4a7c) |= 4;
}
