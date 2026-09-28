/* Glide tick of an ov257 state: the +0x50 timer accumulates the owner's rate and the +0x5c path
 * point is resolved (Ov257_SteerToTarget) into the +0x10 step. Once the +0xc idle byte clears,
 * animation 0x18 plays looped, the +0x3d0 part plays motion 0x15 and the tick hands over to
 * Ov257_RiseTick2. */
typedef struct { int x, y, z; } Vec3;

extern void Ov257_SteerToTarget(int *state, int point, Vec3 *dir, int *speed);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern void Ov107_PostTagUpdate(int owner, int anim, int mode);
extern void Ov107_StartAnim(int part, int motion, int mode);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov257_RiseTick2(int *node);

void Ov257_RiseTick(int *node)
{
    int *state = (int *)node[1];
    Vec3 dir;
    int speed;

    state[0x15] += *(int *)(node[0] + 0x2c);
    Ov257_SteerToTarget(state, state[0x18], &dir, &speed);
    ScaleVec3Fx12(speed, &dir, (Vec3 *)(state + 4));
    if (*(unsigned char *)state[3] != 0) {
        return;
    }
    Ov107_PostTagUpdate(*state, 0x18, 1);
    Ov107_StartAnim(*(int *)(*state + 0x3d0), 0x15, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov257_RiseTick2);
}
