extern void MI_CpuFill8(void *dst, int value, unsigned int size);
extern char *Archive_LoadFile(void *source, int count);

void Ov008_VarTable_Load(void *object, void *source)
{
    char *block;
    int offset;

    MI_CpuFill8(object, 0, 0xc);
    block = Archive_LoadFile(source, 0xe);
    *(char **)object = block;
    offset = *(int *)block;
    *(int *)((char *)object + 4) = *(int *)(block + 4);
    *(char **)((char *)object + 8) = *(char **)object + offset;
}
