/* Posts an animation request, recording its extended index and argument. */

extern void Ov022_PostAnimRequest(int arg0, int arg1, char arg2);
void func_ov022_020b19cc(int arg0, int arg1, char arg2) {
    int c = -1;
    if (arg1 >= 0x1b) c = arg1 - 0x1b;
    *(char *)(arg0 + 0xc) = c;
    *(char *)(arg0 + 0xd) = arg2;
    Ov022_PostAnimRequest(arg0, arg1, arg2);
}
