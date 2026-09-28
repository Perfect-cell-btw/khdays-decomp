/* Compute the offset vector (020cca74) from the owner spline at *(*child+0x388)+0x2c into
 * (child)+0x30; unless the gate byte at *(child+0x10) is set, mark sub-state 2 and dispatch. */
extern void Ov232_rotateVecByOwnerYaw(void *out, int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
struct Vec3_020cd88c { int x, y, z; };
void Ov232_AiFollowUntilAnimEnd(int param_1) {
    int child = *(int *)(param_1 + 4);
    struct Vec3_020cd88c out;
    Ov232_rotateVecByOwnerYaw(&out, param_1, *(int *)(*(int *)child + 0x388) + 0x2c);
    *(struct Vec3_020cd88c *)(child + 0x30) = out;
    if (*(unsigned char *)*(int *)(child + 0x10) != 0) return;
    *(signed char *)(*(int *)child + 0x1c7) = 2;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
