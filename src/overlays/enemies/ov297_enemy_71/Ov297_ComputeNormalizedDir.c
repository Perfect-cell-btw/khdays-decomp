/* Returns the distance from the actor to the point (normalising the direction vector). */

extern void VEC_Subtract(void *a, void *b, void *out);
extern int VEC_Normalize(void *dst, void *src);

int Ov297_ComputeNormalizedDir(int node, int x, int y, int z) {
    int diff[3];

    VEC_Subtract(&x, (void *)(**(int **)(node + 4) + 0xb0), diff);
    return VEC_Normalize(diff, diff);
}
