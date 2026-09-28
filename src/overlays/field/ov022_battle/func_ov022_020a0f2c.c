extern unsigned char func_ov022_020882bc(int arg0);
extern unsigned short QueryActiveStateOrDelegate(void);
extern void Ov107_Region_RequestJoin(int arg0, int arg1);
void func_ov022_020a0f2c(int arg0, int arg1) {
    unsigned int a = func_ov022_020882bc(*(unsigned char *)(arg0 + 9));
    unsigned short b = QueryActiveStateOrDelegate();
    if (a != b) return;
    Ov107_Region_RequestJoin(arg1, *(int *)(arg0 + 0x4ec));
}
