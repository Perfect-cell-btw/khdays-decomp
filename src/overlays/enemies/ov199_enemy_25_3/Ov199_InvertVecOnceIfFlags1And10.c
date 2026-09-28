/* Hit reaction: when the hit flags have bits 0 and 4 set and the velocity has not been reversed
 * yet, reverses it, marks it reversed and clears the timer; returns whether it did. */

extern void ScaleVec3Fx12(int scale, void *src, void *dst);

int Ov199_InvertVecOnceIfFlags1And10(int node, int arg2, unsigned int *arg3) {
    int obj = *(int *)(node + 0x214);
    unsigned int v = (unsigned short)*arg3;
    if ((v & 1) && (v & 0x10)) {
        if (*(int *)(obj + 0x20) != 0) return 0;
        ScaleVec3Fx12(-0x1000, (void *)(obj + 0x14), (void *)(obj + 0x14));
        *(int *)(obj + 0x20) = 1;
        *(int *)(obj + 0x24) = 0;
        return 1;
    }
    return 0;
}
