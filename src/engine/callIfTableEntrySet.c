/* Sets an animation track's frame (wrapped) when the track exists in the model's track table. */

extern void Anim_SetFrameWrapped(unsigned short *p, int a, int b);
void callIfTableEntrySet(int param_1, int param_2, int param_3) {
    if (*(short *)(*(int *)(param_1 + 0x8c) + param_2 * 2) == 0) return;
    Anim_SetFrameWrapped(*(unsigned short **)(param_1 + 0x88), param_2, param_3);
}
