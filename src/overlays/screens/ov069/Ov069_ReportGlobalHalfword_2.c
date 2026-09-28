extern void Ov002_SetRootField85ac(int a, int b);
extern int data_0204be18;

int Ov069_ReportGlobalHalfword_2(unsigned int arg) {
    Ov002_SetRootField85ac(1, *(unsigned short *)(*(char **)&data_0204be18 + 0x196e));
    if (*(unsigned short *)(*(char **)&data_0204be18 + 0x196e) < arg) {
        return 0;
    }
    return 1;
}
