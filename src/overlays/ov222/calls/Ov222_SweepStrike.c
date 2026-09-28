/* Sweep of the ov221 enemy's strike: the entities inside the given sphere are tested one by
 * one -- each whose +2 id bit is clear in the +0x64 mask is pushed 1.0 along the flattened
 * unit direction from the owner's +0x74 (kind +0x58 byte) and, on acceptance, the sphere's
 * centre goes out as the mode-0 message (Ov222_ForwardVecToOwner), reaction 0x12a
 * mode 8 fires at the +8 point and the bit is set. Returns the entity count. */
typedef struct { int x, y, z; } Vec3;
typedef struct { Vec3 pos; int nRadius; } Sphere;

extern int Ov107_CollectSphereOverlaps(int owner, Sphere *query, int *out);
extern void VEC_Subtract(void *a, void *b, Vec3 *d);
extern int VEC_Normalize(Vec3 *a, Vec3 *d);
extern void ScaleVec3Fx12(int scale, Vec3 *v, Vec3 *d);
extern int Ov107_InvokeHitCallback(int hit, int a, int b, int kind, Vec3 *push, int z);
extern void Ov222_ForwardVecToOwner(int *state, Vec3 v, int flag);
struct Ov221Byte8 { unsigned int lo : 8, rest : 24; };
extern void Ov107_BuildAndSendUpdate(int owner, int id, int mode, void *at);

int Ov222_SweepStrike(int *node, Sphere *sphere)
{
    int *state = (int *)node[1];
    int hits[4];
    Vec3 push;
    long i;
    long n;
    unsigned char bit;

    n = Ov107_CollectSphereOverlaps(*state, sphere, hits);
    i = 0;
    if (n > 0) {
        do {
            bit = 1 << *(unsigned short *)(hits[i] + 2);
            if ((*(unsigned char *)((char *)state + 0x64) & bit) == 0) {
                VEC_Subtract((void *)(hits[i] + 0x74), (void *)(*state + 0x74), &push);
                push.y = 0;
                VEC_Normalize(&push, &push);
                ScaleVec3Fx12(0x1000, &push, &push);
                if (Ov107_InvokeHitCallback(hits[i], *state, *(int *)(*state + 0x390), state[0x16] & 0xff, &push, 0) != 0) {
                    Ov222_ForwardVecToOwner(state, sphere->pos, 0);
                    Ov107_BuildAndSendUpdate(*state, 0x12a, 8, (void *)state[2]);
                    *(unsigned char *)((char *)state + 0x64) |= bit;
                }
            }
        } while (++i < n);
    }
    return n;
}
