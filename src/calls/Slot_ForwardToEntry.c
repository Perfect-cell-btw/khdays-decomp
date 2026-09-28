extern void NNS_G2dSetCellAnimationCurrentFrame(int, int);

void Slot_ForwardToEntry(int param_1, int param_2, int param_3) {
    if (param_2 < 0) {
        return;
    }
    NNS_G2dSetCellAnimationCurrentFrame(param_1 + 0x18 + param_2 * 0x8c, param_3);
}
