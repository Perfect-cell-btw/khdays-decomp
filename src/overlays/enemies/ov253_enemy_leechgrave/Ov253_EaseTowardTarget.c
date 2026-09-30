/* Ov253_EaseTowardTarget -- ease the object toward its target: burn the owner's frame delta off the
 * remaining time at ctx[0xb] (never below zero), step the interpolator (Angle_TurnToward) and apply
 * the result to the transform at +0xa0. */
extern int Angle_TurnToward(int a, int b, int c, int d);
extern void Srt_SetRotationAxisAngle(int dst, void *src, int v);
extern int data_02042264;

void Ov253_EaseTowardTarget(int *self) {
    int *ctx = (int *)self[1];
    if (ctx[0xb] > 0) {
        ctx[0xb] = ctx[0xb] - *(int *)(self[0] + 0x2c);
    }
    ctx[4] = Angle_TurnToward(ctx[4], ctx[5], ctx[6], 0);
    Srt_SetRotationAxisAngle(ctx[0] + 0xa0, &data_02042264, ctx[4]);
}
