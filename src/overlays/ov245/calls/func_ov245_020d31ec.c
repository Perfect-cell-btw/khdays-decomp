/* func_ov245_020d31ec -- hop tick: before the +0x44 latch the actor's +0x74 sphere is swept
 * (020c8eb8) and every hit is pushed along the flattened direction from the actor (halved
 * after the +0x4c bounce) through the +0x390 item (020ca918, mode 2): a landing hit plays
 * effect 1 and reaction 0x15a/5 at the +8 anchor and ends the hop. After the latch gravity
 * (-0xc0 * step / 0x88) accumulates in +0x10 and every live, unflagged actor of the scene's
 * +0x80 list is checked: a live +0x22c shape touching the sphere (020c3504) counts as a landing
 * when the actor is the +0x390 item itself, otherwise a hit packet (0x2004, the item's +0x29c
 * strength, the actor's +0x258 kind, the shape) is offered (020c5cfc). Then the step since the
 * last +0x38 position is probed: before the latch, without the +0x4c bounce, a wall hit
 * (01fff920) fires reaction 0x15a/6, raises bit 7 of +0x60 and either bounces (+0x48: velocity
 * zeroed, the anchor clamped to y = 0, effects 1 and 2) or ends the hop; with the bounce the
 * anchor is re-clamped. A solid floor probe (01fff8e8, radius 0.1875) fires reaction 0x15a/6;
 * otherwise within 100.0 of the origin the +0x24 timer runs up and under 20.0 the hop goes on.
 * Ending plays effect 1 at the anchor, sub-state 0 and frees the node slot. */
typedef struct { int x, y, z; } Vec3;
struct Sphere { Vec3 centre; int radius; };
struct hw60 { unsigned short lo : 8, hi : 8; };
struct w8 { unsigned int lo : 8, rest : 24; };
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

struct HitPacket {
    u32 flagsLo : 16;
    u32 flagsHi : 16;
    Vec3 normal;
    int field_10 : 16;
    int field_12 : 16;
    int field_14 : 16;
    int field_16 : 16;
    void *field_18;
    signed char field_1c;
    u8 pad01d[3];
    int field_20;
    u32 flags24Lo : 16;
    u32 flags24Hi : 16;
    int field_28;
};

extern int func_ov107_020c8eb8(int actor, struct Sphere *sphere, int *out);
extern void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int func_01ff8d18(const Vec3 *v, Vec3 *out);
extern void func_01ffa724(int scale, const Vec3 *v, Vec3 *out);
extern int func_ov107_020ca918(int hit, int a, int b, int kind, Vec3 *push, int z);
extern void func_ov107_020c0b90(int actor, int effect, Vec3 v, int flag);
extern void func_ov107_020c5af8(int actor, int id, int kind, void *anchor);
extern void func_0203c634(int *node, int slot, void *cb);
extern int *func_01fffd70(void *list);
extern int *func_01fffd8c(void *list);
extern int func_ov107_020c3504(int shape, struct Sphere *sphere, int a);
extern int func_ov107_020c5cfc(int other, int source, struct HitPacket *packet);
extern void func_ov107_020c5c54(int actor, Vec3 *pos);
extern int func_01fff920(int collision, const Vec3 *from, const Vec3 *step);
extern int func_01fff8e8(int collision, const Vec3 *from, const Vec3 *step, int radius, void *ignore);
extern int VEC_Mag(const Vec3 *v);
extern const Vec3 data_02041dc8;

static inline void VEC_Set(Vec3 *p, int x, int y, int z) { p->x = x; p->y = y; p->z = z; }

void func_ov245_020d31ec(int *node) {
    int *state = (int *)node[1];
    struct Sphere sphere;
    Vec3 step;
    int hits[4];
    Vec3 push;
    int scene = *(int *)(*state + 4);
    long n;
    int nHits;
    int *entry;
    int other;
    int *shape;
    int hit;

    sphere = *(struct Sphere *)(*state + 0x74);
    if (state[0x11] == 0) {
        nHits = func_ov107_020c8eb8(*state, &sphere, hits);
        for (n = 0; n < nHits; n++) {
            VEC_Subtract((Vec3 *)(hits[n] + 0x74), (Vec3 *)(*state + 0x74), &push);
            push.y = 0;
            func_01ff8d18(&push, &push);
            if (state[0x13] != 0) {
                func_01ffa724(0x800, &push, &push);
            }
            if (func_ov107_020ca918(hits[n], *state, *(int *)(*state + 0x390), 2, &push, 0) != 0) {
                func_ov107_020c0b90(*state, 1, *(Vec3 *)state[2], 0);
                func_ov107_020c5af8(*state, 0x15a, 5, (void *)state[2]);
                *(unsigned char *)(*state + 0x1c7) = 0;
                func_0203c634(node, *(signed char *)((char *)node + 0x20), 0);
                return;
            }
        }
    } else {
        n = 0;
        state[4] += *(int *)(node[0] + 0x2c) * -0xc0 / 0x88;
        entry = func_01fffd70((void *)(scene + 0x80));
        other = entry == 0 ? 0 : *entry;
        while (other != 0) {
            if ((((struct hw60 *)(other + 0x60))->lo & 1) != 0 && (*(u16 *)(other + 0x100 + 0xac) & 7) == 0) {
                shape = func_01fffd70((void *)(other + 0x22c));
                while (shape != 0) {
                    if ((((struct w8 *)(shape + 2))->lo & 1) != 0 && func_ov107_020c3504(shape[0], &sphere, 0) != 0) {
                        struct HitPacket packet = {0};
                        if (other == *(int *)(*state + 0x390)) {
                            n = 1;
                        } else {
                            packet.flagsLo = 0x2004;
                            packet.field_10 = *(u16 *)(*(int *)(*state + 0x390) + 0x200 + 0x9c);
                            packet.field_14 = *(int *)(*state + 0x258);
                            packet.field_18 = shape;
                            if (func_ov107_020c5cfc(other, *(int *)(*state + 0x25c), &packet) != 0) {
                                n = 1;
                            }
                            break;
                        }
                    }
                    shape = func_01fffd8c((void *)(other + 0x22c));
                }
                if (n != 0) {
                    func_ov107_020c0b90(*state, 1, *(Vec3 *)state[2], 0);
                    func_ov107_020c5af8(*state, 0x15a, 5, (void *)state[2]);
                    *(unsigned char *)(*state + 0x1c7) = 0;
                    func_0203c634(node, *(signed char *)((char *)node + 0x20), 0);
                    return;
                }
            }
            entry = func_01fffd8c((void *)(scene + 0x80));
            other = entry == 0 ? 0 : *entry;
        }
    }
    VEC_Subtract((Vec3 *)state[2], (Vec3 *)(state + 14), &step);
    *(Vec3 *)(state + 14) = *(Vec3 *)state[2];
    if (state[0x11] == 0) {
        Vec3 flatAnchor;
        int *anchor = (int *)state[2];
        VEC_Set(&flatAnchor, anchor[0], 0, anchor[2]);
        if (state[0x13] != 0) {
            *(Vec3 *)(state + 3) = data_02041dc8;
            func_ov107_020c5c54(*state, &flatAnchor);
        } else if (func_01fff920(*(int *)(scene + 0x7c), (Vec3 *)state[2], &step) != 0) {
            Vec3 at = *(Vec3 *)state[2];
            at.y = 0;
            func_ov107_020c5af8(*state, 0x15a, 6, (void *)state[2]);
            {
                u16 hw = *(u16 *)(*state + 0x60);
                *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
                    ((((((unsigned int)hw << 0x10) >> 0x18) | 0x80) << 0x18) >> 0x10);
            }
            if (state[0x12] != 0) {
                *(Vec3 *)(state + 3) = data_02041dc8;
                func_ov107_020c5c54(*state, &flatAnchor);
                state[0x13] = 1;
                func_ov107_020c0b90(*state, 1, at, 0);
                func_ov107_020c0b90(*state, 2, *(Vec3 *)state[2], 0);
            } else {
                func_ov107_020c0b90(*state, 1, at, 0);
                *(unsigned char *)(*state + 0x1c7) = 0;
                func_0203c634(node, *(signed char *)((char *)node + 0x20), 0);
                return;
            }
        }
    }
    hit = func_01fff8e8(*(int *)(scene + 0x7c), (Vec3 *)state[2], &step, 0x300, 0);
    if (hit != 0 && *(int *)(hit + 8) == 0) {
        func_ov107_020c5af8(*state, 0x15a, 6, (void *)state[2]);
    } else if (VEC_Mag((Vec3 *)state[2]) <= 0x64000) {
        state[9] += *(int *)(node[0] + 0x2c);
        if (state[9] < 0x14000) {
            return;
        }
    }
    func_ov107_020c0b90(*state, 1, *(Vec3 *)state[2], 0);
    *(unsigned char *)(*state + 0x1c7) = 0;
    func_0203c634(node, *(signed char *)((char *)node + 0x20), 0);
}
