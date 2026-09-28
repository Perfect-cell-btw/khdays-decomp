/* Glide tick of an ov255 state: the +0x50 timer accumulates the owner's rate and the +0x5c path point is resolved (Ov255_SteerToTarget) into the
 * +0x10 step. Once the +0xc idle byte clears, animation 0x22 and the +0x3a4 part's motion 0x1d play
 * looped, bit 6 of the owner's +0x60 high byte clears and the tick hands over to
 * Ov255_GlideToLandTick4. */
typedef struct { int x, y, z; } Vec3;
struct hw60 { unsigned short lo : 8, hi : 8; };

extern void Ov255_SteerToTarget(int *state, int point, Vec3 *dir, int *speed);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern void Ov107_PostTagUpdate(int owner, int anim, int mode);
extern void Ov107_StartAnim(int part, int motion, int mode);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov255_GlideToLandTick4(int *node);

void Ov255_GlideTick3(int *node)
{
    int *state = (int *)node[1];
    Vec3 dir;
    int speed;

    state[0x14] += *(int *)(node[0] + 0x2c);
    Ov255_SteerToTarget(state, state[0x17], &dir, &speed);
    ScaleVec3Fx12(speed, &dir, (Vec3 *)(state + 4));
    if (*(unsigned char *)state[3] != 0) {
        return;
    }
    Ov107_PostTagUpdate(*state, 0x22, 1);
    Ov107_StartAnim(*(int *)(*state + 0x3a4), 0x1d, 1);
    ((struct hw60 *)(*state + 0x60))->hi &= ~0x40;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov255_GlideToLandTick4);
}
