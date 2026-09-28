extern void MI_CpuFill8(void *p, int a, int b);
extern int *Archive_LoadFile(int arg, int b);
void Ov007_ReleaseAndFreeField2644(int *out, int arg) {
    int *r;
    int t;
    MI_CpuFill8(out, 0, 0xc);
    r = Archive_LoadFile(arg, 0xe);
    out[0] = (int)r;
    t = r[0];
    out[1] = r[1];
    out[2] = out[0] + t;
}
