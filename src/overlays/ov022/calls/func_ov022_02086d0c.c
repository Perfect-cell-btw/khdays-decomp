extern void Tween_Configure(unsigned int *arg0, int arg1, int arg2, int arg3, int arg4);
extern void Tween_Start(int arg0);
extern int data_ov022_020b2e74;

void func_ov022_02086d0c(int arg0) {
    int p = *(int *)&data_ov022_020b2e74;
    if (arg0 != 0) {
        Tween_Configure((unsigned int *)(p + 0x1e0), 1, 0, 0x10000, 400);
        Tween_Start(p + 0x1e0);
        return;
    }
    Tween_Configure((unsigned int *)(p + 0x1e0), 2, 0x10000, 0, 400);
    Tween_Start(p + 0x1e0);
}
