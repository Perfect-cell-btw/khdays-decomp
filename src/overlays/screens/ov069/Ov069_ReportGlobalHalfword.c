/* Reports a global counter to the field root, then returns whether it is at least the value. */

extern void Ov002_SetRootField85ac(int a, int b);
extern int data_0204be18;

int Ov069_ReportGlobalHalfword(unsigned int arg) {
    Ov002_SetRootField85ac(1, *(unsigned short *)(*(char **)&data_0204be18 + 0x196c));
    if (*(unsigned short *)(*(char **)&data_0204be18 + 0x196c) < arg) {
        return 0;
    }
    return 1;
}
