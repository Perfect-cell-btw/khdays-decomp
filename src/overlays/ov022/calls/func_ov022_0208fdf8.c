extern void Ov022_EnterBlockReaction(int arg0, int arg1, int arg2, int arg3);
void func_ov022_0208fdf8(int arg0, int arg1, int arg2, int arg3) {
    int e = arg0 + *(int *)(arg0 + 0xc) * 4;
    int t = *(int *)(e + 0x18);
    Ov022_EnterBlockReaction(arg0, e, arg2, arg3);
    *(char *)(t + 0x118) = 1;
    *(int *)(t + 0x12c) = 0xa000;
    *(int *)(t + 0x120) = *(int *)(t + 0x140);
    *(int *)(t + 0x138) = 0;
    {
        int v = *(int *)(t + 0x14c);
        *(int *)(t + 0xc0) = v;
        *(int *)(t + 0xbc) = v;
        *(int *)(t + 0xb8) = v;
    }
}
