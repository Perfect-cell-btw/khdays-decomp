extern void MI_CpuFill8(void *dst, int value, int size);
extern char gObjKeyBuckets[];
extern char gObjSystem[];
/* Clear the 0x100-byte scratch table and reset the three cursor words of its header. */
void Obj_InitSystem(void) {
    MI_CpuFill8(gObjKeyBuckets, 0, 0x100);
    *(int *)(gObjSystem + 0xc) = 0;
    *(int *)(gObjSystem + 4) = 0;
    *(int *)(gObjSystem + 8) = 0;
}
