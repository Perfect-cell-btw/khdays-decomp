/* Timed step: advances the timer; once the gate byte is clear, launches the actor forward (its
 * facing times 0.5, with a fixed upward speed), posts a pose, clears the timer and the swing flag
 * and installs the leap step. */

extern void Vec3TransformViaTempMtx();
extern void ScaleVec3Fx12();
extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern int data_02042258[];
extern void Ov251_LeapTick(void);
void Ov251_stateTimerTransformVec(int *node) {
    int *state = (int *)node[1];
    state[0x1b] = state[0x1b] + *(int *)(*node + 0x2c);
    if (*(unsigned char *)state[3] != 0) return;
    Vec3TransformViaTempMtx(state + 0x1e, *state + 0xa0, data_02042258);
    ScaleVec3Fx12(0x800, state + 0x1e, state + 0x1e);
    state[0x1f] = 0x400;
    Ov107_PostTagUpdate(*state, 0xe, 0);
    state[7] = 0;
    *(signed char *)((char *)state + 0x50) = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov251_LeapTick);
}
