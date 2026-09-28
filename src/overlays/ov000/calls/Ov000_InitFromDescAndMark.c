extern int ObjNode_InitFromDesc();

void Ov000_InitFromDescAndMark(char *p)
{
    ObjNode_InitFromDesc(p);
    *(int *)(p + 0x4a7c) |= 4;
}
