/* Returns the current frame of an effect pool entry's first animation track. */

extern int Anim_GetFrame(int arg0, int arg1);
int func_ov022_02089604(int arg0, int arg1) {
    return Anim_GetFrame(arg1 * 0x114 + *(int *)(*(int *)(arg0 + 0x20) + 0xc) + 4, 0);
}
