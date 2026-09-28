extern void Anim_GetFrame(int arg0, int arg1);
void func_ov022_02089604(int arg0, int arg1) {
    Anim_GetFrame(arg1 * 0x114 + *(int *)(*(int *)(arg0 + 0x20) + 0xc) + 4, 0);
}
