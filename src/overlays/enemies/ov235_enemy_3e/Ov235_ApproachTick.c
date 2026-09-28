/* Approach tick of an ov235 state: the +0x40 rate is the frame rate x 3 and the nearest target
 * (020cab14) becomes +0x5c; without one sub-state 2 is requested. Otherwise the path point is
 * resolved (Ov235_SteerToTarget) into the +0x10 step and, once the +0xc idle byte clears, the
 * next sub-state is 0xc when the +0x4c cooldown has run out and the gap between the two collision
 * radii exceeds 4.0, else 2. */
typedef struct { int x, y, z; } Vec3;

extern int Ov107_FindNearestObject(int obj, int kind);
extern void Ov235_SteerToTarget(int *state, int point, Vec3 *dir, int *speed);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern void VEC_Subtract(const void *a, const void *b, Vec3 *out);
extern int VEC_Normalize(const Vec3 *v, Vec3 *out);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov235_ApproachTick(int *node)
{
    int *state = (int *)node[1];
    Vec3 dir;
    Vec3 d;
    int speed;

    state[0x10] = *(int *)(node[0] + 0x2c) * 30 / 10;
    state[0x17] = Ov107_FindNearestObject(*state, 0);
    if (state[0x17] == 0) {
        *(unsigned char *)(*state + 0x1c7) = 2;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    Ov235_SteerToTarget(state, state[0x17], &dir, &speed);
    ScaleVec3Fx12(speed, &dir, (Vec3 *)(state + 4));
    if (*(unsigned char *)state[3] != 0) {
        return;
    }
    {
        int target;
        int owner;
        int gap;

        owner = *state;
        target = state[0x17];

        VEC_Subtract((void *)(target + 0x74), (void *)(owner + 0x74), &d);
        gap = VEC_Normalize(&d, &d) - *(int *)(owner + 0x80) - *(int *)(target + 0x80);
        if (state[0x13] <= 0 && gap > 0x4000) {
            *(unsigned char *)(*state + 0x1c7) = 0xc;
        } else {
            *(unsigned char *)(*state + 0x1c7) = 2;
        }
    }
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
