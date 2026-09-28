/* Returns an animation track's current frame, or 0 when the track is not in the model's track
 * table. */

extern int Anim_GetFrame(unsigned short *p, int i);
int queryTableEntry(int param_1, int param_2) {
    if (*(short *)(*(int *)(param_1 + 0x8c) + param_2 * 2) == 0) return 0;
    return Anim_GetFrame(*(unsigned short **)(param_1 + 0x88), param_2);
}
