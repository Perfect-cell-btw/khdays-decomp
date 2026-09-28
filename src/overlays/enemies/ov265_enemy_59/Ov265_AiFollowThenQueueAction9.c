/* Compute the offset vector (020cca74) from the owner spline at *(*child+0x388)+0x2c into
 * (child)+0x30; unless the gate byte at *(child+0x10) is set, mark sub-state 9 and dispatch. */
extern void Ov265_rotateVecByOwnerYaw(void *out, int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
struct Vec3_020cec2c { int x, y, z; };
void Ov265_AiFollowThenQueueAction9(int param_1) {
    int child = *(int *)(param_1 + 4);
    struct Vec3_020cec2c out;
    Ov265_rotateVecByOwnerYaw(&out, param_1, *(int *)(*(int *)child + 0x388) + 0x2c);
    *(struct Vec3_020cec2c *)(child + 0x30) = out;
    if (*(unsigned char *)*(int *)(child + 0x10) != 0) return;
    *(signed char *)(*(int *)child + 0x1c7) = 9;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
