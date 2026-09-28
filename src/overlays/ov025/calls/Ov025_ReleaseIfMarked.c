/* When status bit 2 of the flag word at param_1+0x4a7c is set, run Obj_Release
 * and clear that bit. */
extern void Obj_Release(int obj);

void Ov025_ReleaseIfMarked(int param_1) {
    if ((((unsigned int)*(unsigned int *)(param_1 + 0x4a7c) << 0x1d) >> 0x1f) == 1) {
        Obj_Release(param_1);
        *(int *)(param_1 + 0x4a7c) &= ~4;
    }
}
