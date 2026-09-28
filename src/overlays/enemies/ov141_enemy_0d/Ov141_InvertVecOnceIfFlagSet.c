/* Hit reaction: when bit 0 of the flags is set and the velocity has not been reversed yet, reverses
 * it (+0x18), marks it reversed and clears the timer; returns whether it did. */

extern void ScaleVec3Fx12(int scale, void *src, void *dst);

int Ov141_InvertVecOnceIfFlagSet(int node, int arg2, unsigned int *arg3) {
    int obj = *(int *)(node + 0x214);
    if ((unsigned short)*arg3 & 1) {
        if (*(int *)(obj + 0x20) != 0) return 0;
        ScaleVec3Fx12(-0x1000, (void *)(obj + 0x14), (void *)(obj + 0x14));
        *(int *)(obj + 0x20) = 1;
        *(int *)(obj + 0x24) = 0;
        return 1;
    }
    return 0;
}
