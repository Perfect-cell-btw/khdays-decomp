/* Sweep tick of the ov268 enemy's item (x3 with ov208/ov209). The +0x40 timer accumulates the
 * item's rate; up to 0x330 a sphere of radius 1.62 at the +8 point plus the +0x18 direction
 * scaled 2.43 is swept over the owner's (+0x394) list: every entity whose id bit is clear in the
 * +0x45 mask is pushed along the flattened unit direction from the item's +0x74 point (kind 3,
 * from the owner); on acceptance the owner spawns effect 1 at the +8 point, reaction 0/0x53
 * fires there and the bit is set. Past 0xf68, if the owner's +0x1c6 phase no longer matches
 * +0x44 the item's +0x1c7 request is cleared and the tick ends; otherwise effects 2 (item) and 3
 * spawn at the origin, reaction 0x15f mode 0xe fires at the +8 point, the timer restarts and
 * the tick hands over to Ov268_TimerFlagFirePushTwice. */
typedef unsigned char u8;
typedef struct { int x, y, z; } Vec3;
typedef struct { Vec3 pos; int radius; } Sphere;

extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern void VEC_Add(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int Ov107_CollectSphereOverlaps(int owner, Sphere *sphere, int *out);
extern void VEC_Subtract(const void *a, const void *b, Vec3 *out);
extern int VEC_Normalize(const Vec3 *v, Vec3 *out);
extern int Ov107_InvokeHitCallback(int hit, int a, int b, int kind, Vec3 *push, int z);
extern void func_ov107_020c0b90(int actor, int a, Vec3 v, int b);
extern void Ov107_BuildAndSendUpdate(int owner, int id, int mode, void *at);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern const Vec3 data_02041dc8;
extern void Ov268_TimerFlagFirePushTwice(int *node);

void Ov268_ItemSweepTick(int *node)
{
    int *state = (int *)node[1];
    Sphere sphere;
    int hits[4];
    Vec3 push;
    Vec3 zero;
    int i;
    int n;
    unsigned int mask;
    int item;

    state[0x10] += *(int *)(*node + 0x2c);
    if (state[0x10] <= 0x330) {
        ScaleVec3Fx12(0x26e2, (Vec3 *)(state + 6), &sphere.pos);
        VEC_Add(&sphere.pos, (Vec3 *)state[2], &sphere.pos);
        sphere.radius = 0x19ec;
        n = Ov107_CollectSphereOverlaps(*(int *)(*state + 0x394), &sphere, hits);
        i = 0;
        if (n > 0) {
            do {
                mask = (1 << *(unsigned short *)(hits[i] + 2)) & 0xff;
                if ((*((u8 *)state + 0x45) & mask) == 0) {
                    VEC_Subtract((void *)(hits[i] + 0x74), (void *)(*state + 0x74), &push);
                    push.y = 0;
                    VEC_Normalize(&push, &push);
                    if (Ov107_InvokeHitCallback(hits[i], *state, *(int *)(*state + 0x394), 3, &push, 0) != 0) {
                        func_ov107_020c0b90(*(int *)(*state + 0x394), 1, *(Vec3 *)state[2], 0);
                        Ov107_BuildAndSendUpdate(*state, 0, 0x53, (void *)state[2]);
                        *((u8 *)state + 0x45) |= mask;
                    }
                }
            } while (++i < n);
        }
    }
    if (state[0x10] < 0xf68) {
        return;
    }
    item = *state;
    if (*((signed char *)state + 0x44) != *(signed char *)(*(int *)(item + 0x394) + 0x1c6)) {
        *(u8 *)(item + 0x1c7) = 0;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    zero = data_02041dc8;
    func_ov107_020c0b90(item, 2, zero, 0);
    func_ov107_020c0b90(*state, 3, zero, 0);
    Ov107_BuildAndSendUpdate(*state, 0x15f, 0xe, (void *)state[2]);
    state[0x10] = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov268_TimerFlagFirePushTwice);
}
