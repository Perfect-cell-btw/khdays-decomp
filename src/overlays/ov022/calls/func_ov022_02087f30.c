extern int data_ov022_020b2e78;
extern int Ov022_GetGlobal34(void);
void func_ov022_02087f30(void) {
    int e = ((int *)&data_ov022_020b2e78)[1];
    if (*(int *)(e + 0x40) == 0) {
        if (*(char *)(e + 0x3d) != -1) *(char *)(e + 0x3d) = -1;
        return;
    }
    {
        int v = *(int *)(e + 0x40) - Ov022_GetGlobal34();
        *(int *)(e + 0x40) = v;
        if (v < 0) *(int *)(e + 0x40) = 0;
    }
}
