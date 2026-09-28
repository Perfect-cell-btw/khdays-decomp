/* Take-off tick of an ov255 state: the +0x40 rate follows the frame rate and the nearest target
 * (020cab14) becomes +0x5c; without one sub-state 2 is requested. Otherwise the path point is
 * resolved (Ov255_SteerToTarget) into the +0x10 step and, once the +0xc idle byte clears, animation
 * 2 and the +0x3a4 part's motion 1 play looped, +0x50 and +0x66 clear and the tick hands over to
 * Ov255_WindUpTick. */
typedef struct { int x, y, z; } Vec3;

extern int Ov107_FindNearestObject(int obj, int kind);
extern void Ov255_SteerToTarget(int *state, int point, Vec3 *dir, int *speed);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern void Ov107_PostTagUpdate(int owner, int anim, int mode);
extern void Ov107_StartAnim(int part, int motion, int mode);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov255_WindUpTick(int *node);

void Ov255_TakeOffTick(int *node)
{
    int *state = (int *)node[1];
    Vec3 dir;
    int speed;

    state[0x10] = *(int *)(node[0] + 0x2c) * 30 / 30;
    state[0x17] = Ov107_FindNearestObject(*state, 0);
    if (state[0x17] == 0) {
        *(unsigned char *)(*state + 0x1c7) = 2;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    Ov255_SteerToTarget(state, state[0x17], &dir, &speed);
    ScaleVec3Fx12(speed, &dir, (Vec3 *)(state + 4));
    if (*(unsigned char *)state[3] != 0) {
        return;
    }
    Ov107_PostTagUpdate(*state, 2, 1);
    Ov107_StartAnim(*(int *)(*state + 0x3a4), 1, 1);
    state[0x14] = 0;
    *((unsigned char *)state + 0x66) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov255_WindUpTick);
}
