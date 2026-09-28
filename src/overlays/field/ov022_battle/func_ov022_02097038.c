extern void Anim_SetFrameWrapped(unsigned short *arg0, int arg1, int arg2);
void func_ov022_02097038(int arg0, int arg1) {
    Anim_SetFrameWrapped((unsigned short *)(*(int *)(arg0 + 0x20) + 4), 0, arg1);
    *(int *)(arg0 + 0x7b0) = arg1;
}
