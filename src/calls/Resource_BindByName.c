#pragma thumb on
extern void MI_CpuFill8(void *dest, int val, int size);
extern int Archive_LoadFile(char *name, int kind);
extern void StreamReader_InitU16(int *a, int *b);
/* Zero a 0xc-byte handle, bind the Archive_LoadFile(name,0xe) resource at handle[2],
 * then run StreamReader_InitU16 on it. */
void Resource_BindByName(unsigned int *handle, char *name) {
    MI_CpuFill8(handle, 0, 0xc);
    handle[2] = Archive_LoadFile(name, 0xe);
    StreamReader_InitU16((int *)handle, (int *)handle[2]);
}
