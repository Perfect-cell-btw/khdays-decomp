/* d0bbc */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x, y, z; } Vec3;
typedef struct { Vec3 center; int nRadius; } Sphere;

extern int Ov107_CollectSphereOverlaps(int owner, Sphere *sphere, int *hits);
extern void VEC_Subtract(const void *a, const void *b, Vec3 *out);
extern int VEC_Normalize(const Vec3 *v, Vec3 *out);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern int Ov107_InvokeHitCallback(int hit, int owner, int item, int kind, Vec3 *push, int z);
extern void Ov107_BuildAndSendUpdate(int owner, int id, int mode, void *at);
extern void func_ov107_020c0b90(int owner, int mode, Vec3 at, int flag);
extern void Task_MarkFinished(int *node);

void Ov258_RiseBurstTick(int *node)
{
    int *state = (int *)node[1];
    int hits[4];
    Sphere sphere;
    Vec3 push;
    long i;
    long n;
    u8 bit;

    *(int *)(*state + 0x5c) &= ~2;
    state[5] += *(int *)(node[0] + 0x2c);
    if (*(int *)(state[1] + 0x50) == 1 && state[5] < 0xaa0) {
        sphere.center = *(Vec3 *)(state + 2);
        sphere.nRadius = 0x3000;
        n = Ov107_CollectSphereOverlaps(state[1], &sphere, hits);
        for (i = 0; i < n; i++) {
            bit = 1 << *(u16 *)(hits[i] + 2);

            VEC_Subtract((void *)(hits[i] + 0x190), state + 2, &push);
            VEC_Normalize(&push, &push);
            if (push.y != 0) {
                int half = push.y / 2;

                push.y = 0;
                push.x += half;
                push.z += half;
            }
            ScaleVec3Fx12(0x800, &push, &push);
            push.z += 0x3000;
            push.y += 0x1000;
            if ((*((u8 *)state + 0x18) & bit) != 0) {
                continue;
            }
            if (Ov107_InvokeHitCallback(hits[i], state[1], state[1], 3, &push, 0) == 0) {
                continue;
            }
            Ov107_BuildAndSendUpdate(state[1], (short)(*(int *)(state[1] + 0x460) != 0 ? 0x180 : 0x17b), 0x10,
                                (void *)(hits[i] + 0x190));
            func_ov107_020c0b90(state[1], 7, *(Vec3 *)(hits[i] + 0x190), 0);
            *((u8 *)state + 0x18) |= bit;
        }
    }
    if (*(u8 *)(*state + 0xad) != 0) {
        return;
    }
    *(int *)(state[1] + (*((signed char *)state + 0x1a) + 0x1b) * 8 + 0x468) = 0;
    Task_MarkFinished(node);
}
