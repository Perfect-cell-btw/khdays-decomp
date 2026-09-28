extern void ReleaseField74AndCleanup(int arg0);
extern void Ov022_ClearFields(unsigned int *arg0);

void func_ov022_02094c44(unsigned int *arg0, int arg1, int arg2, int arg3) {
    int i;
    unsigned int *p;
    if ((*arg0 & 1) != 0) {
        i = 0;
        p = arg0 + 3;
        do {
            ReleaseField74AndCleanup((int)p);
            i = i + 1;
            p = p + 0x42;
        } while (i < 3);
        Ov022_ClearFields(arg0);
    }
}
