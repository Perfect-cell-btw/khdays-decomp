/* Forward to NNS_G2dSetCellAnimationCurrentFrame with entry `index` of the stride-0x8c slot array
 * that starts at base+0x18; negative indices are ignored. Same array as Slot_SetMode2Bit. */

extern void NNS_G2dSetCellAnimationCurrentFrame(int, int);

void Slot_ForwardToEntry(int param_1, int param_2, int param_3) {
    if (param_2 < 0) {
        return;
    }
    NNS_G2dSetCellAnimationCurrentFrame(param_1 + 0x18 + param_2 * 0x8c, param_3);
}
