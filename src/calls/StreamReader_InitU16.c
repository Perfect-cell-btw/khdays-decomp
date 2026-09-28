extern void func_02014720(void *arg, void *ptr);
extern void Stream_ReadU16(void);

void StreamReader_InitU16(int *ptr, void *arg) {
    func_02014720(arg, ptr);
    ptr[1] = (int)Stream_ReadU16;
}
