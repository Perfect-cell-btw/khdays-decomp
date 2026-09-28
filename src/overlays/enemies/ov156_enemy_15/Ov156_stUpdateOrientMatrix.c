/* Orientation step: turns the heading toward its target unless the actor is locked, combines it
 * with the ground-normal rotation into the model's SRT, and counts the delay timer down. */

extern int Angle_TurnToward(int a, int b, int c, int d);
extern void QuatFromAxisAngle(void *dst, void *m, int v);
extern void Quat_FromTwoVectors(void *dst, void *m, int v);
extern void Quat_Multiply(void *dst, void *a, void *b);
extern void Srt_SetRotationQuat(void *dst, void *m);
extern int data_02042264[];

void Ov156_stUpdateOrientMatrix(int *node) {
    int *state = (int *)node[1];
    struct { int mtx0[4], mtx1[4]; } f;
    if ((*(unsigned char *)(*state + 0x1c4) & 2) == 0) {
        state[4] = Angle_TurnToward(state[4], state[5], state[0xc], 0);
    }
    QuatFromAxisAngle(f.mtx0, data_02042264, state[4]);
    Quat_FromTwoVectors(f.mtx1, data_02042264, *state + 0x124);
    Quat_Multiply(f.mtx1, f.mtx1, f.mtx0);
    Srt_SetRotationQuat((void *)(*state + 0xa0), f.mtx1);
    if (state[0xd] < 0) return;
    state[0xd] = state[0xd] - *(int *)(node[0] + 0x2c);
}
