/* State step: acquires the nearest target (or queues action 2 and ends the step without one),
 * derives the speed from the owner's frame step, sets the velocity from the action resource, and
 * once the gate byte is clear posts pose 4 and installs the queue-on-flag-clear step. */

extern int Ov107_FindNearestObject();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern int Ov107_ActionResource_GetOffsetAndScale();
extern void Vec3TransformViaTempMtx();
extern void ScaleVec3Fx12();
extern void Ov107_PostTagUpdate();
extern void Ov205_AiStep_QueueAction2OnFlag28Clear_2(void);
void Ov205_stateAcquireTransform(int *node, int p2, int p3, int param_4) {
    int *state = (int *)node[1];
    int buf[3];
    int uStack_14 = param_4;
    int t = Ov107_FindNearestObject(*state, 0);
    state[1] = t;
    if (t == 0) {
        *(signed char *)(*state + 0x1c7) = 2;
        SetIndexedSlot(node, *(signed char *)(node + 8), 0);
        return;
    }
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[0xf] = v / 10;
    }
    {
        int scale = Ov107_ActionResource_GetOffsetAndScale(*(int *)(*state + 0x390), buf);
        Vec3TransformViaTempMtx(state + 2, *state + 0xa0, buf);
        ScaleVec3Fx12(scale, state + 2, state + 2);
    }
    if (*(unsigned char *)state[10] == 0) {
        Ov107_PostTagUpdate(*state, 4, 0);
        SetIndexedSlot(node, *(signed char *)(node + 8), Ov205_AiStep_QueueAction2OnFlag28Clear_2);
    }
}
