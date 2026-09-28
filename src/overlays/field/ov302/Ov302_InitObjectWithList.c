/* Initialises an encounter query: sets up its list and resource record, loads its table and runs
 * the query for the selector. */

extern void MI_CpuFill8(void *dst, int value, int size);
extern void NNS_FndInitList(void *list, int objectSize);
extern void Ov002_InitResourceRecord(void *this_, void *vtable);
extern int Archive_LoadFile(int arg0, int arg1);
extern void Ov302_QueryFieldBySelector(int this_, int arg1, int arg2);
extern void data_ov302_020cc740(void);

void Ov302_InitObjectWithList(int this_, int *init) {
    MI_CpuFill8((void *)this_, 0, 0x24);
    NNS_FndInitList((void *)(this_ + 0x18), 0x4c);
    Ov002_InitResourceRecord((void *)this_, data_ov302_020cc740);
    *(int *)(this_ + 0xc) = init[2];
    *(int *)(this_ + 0x14) = Archive_LoadFile(init[0], 0xe);
    Ov302_QueryFieldBySelector(this_, init[2], init[1]);
}
