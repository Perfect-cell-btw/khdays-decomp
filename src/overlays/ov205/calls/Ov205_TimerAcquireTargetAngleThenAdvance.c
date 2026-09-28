typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

typedef struct ActorFlags60 {
    unsigned short lo : 8;
    unsigned short hi : 8;
} ActorFlags60;

extern int Ov107_FindNearestObject(int actor, int arg);
extern void VEC_Subtract(Vec3 *a, Vec3 *b, Vec3 *out);
extern int func_020050b4(int x, int z);
extern void Ov107_PostTagUpdate(int actor, int a, int b);
extern void SetIndexedSlot(void *node, int idx, void *next);
extern void Ov205_AiStep_QueueAction2OnFlag28Clear(void);

void Ov205_TimerAcquireTargetAngleThenAdvance(int *node) {
    Vec3 delta;
    int *frame = (int *)node[0];
    int *state = (int *)node[1];
    int timer = state[0xb] + frame[0xb];
    int target;
    int angle;

    state[0xb] = timer;
    if (timer < 0x6ee) return;

    target = Ov107_FindNearestObject(*state, 0);
    state[0x1] = target;
    if (target != 0) {
        VEC_Subtract((Vec3 *)(target + 0x74), (Vec3 *)state[0x9], &delta);
        angle = func_020050b4(delta.x, delta.z);
        state[0xd] = state[0xe] = angle;
    }

    ((ActorFlags60 *)(*state + 0x60))->hi &= ~0x80;
    Ov107_PostTagUpdate(*state, 0, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov205_AiStep_QueueAction2OnFlag28Clear);
}
