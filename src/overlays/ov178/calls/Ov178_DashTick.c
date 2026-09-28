/* Dash tick of the ov178 enemy (x3: ov178/179/180): advances the +0x48 phase by the node's
 * +0x2c speed and keeps the previous step (+0x20 <- +0x38). Until the phase passes 0x2fd0 it
 * sweeps the actor's +0x74 sphere through the pool's collision query and, for every hit whose
 * kind bit (1 << +2) is not yet in the +0x86 mask, applies hit 0 with the 0x600-scaled step as
 * the push; a landed hit pushes the target position plus that push to the render hook (cmd 4),
 * records the kind bit and spawns effect 0x143 (7) there. Once the sub-state is idle (-1), an
 * unflagged actor -- or one that still found targets -- rolls 1-in-5 for sub-state 6, else 5. */
typedef struct { int x, y, z; } Vec3;
typedef struct { int w[4]; } Vec4;

extern void VEC_Normalize(const Vec3 *v, Vec3 *out);
extern void ScaleVec3Fx12(int scale, const Vec3 *v, Vec3 *out);
extern int Ov107_CollectSphereOverlaps(int owner, Vec4 *src, int *out);
extern int Ov107_InvokeHitCallback(int victim, int a, int b, int mode, Vec3 *push, int flags);
extern void VEC_Add(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern void func_ov107_020c0b90(int obj, int cmd, Vec3 v, int flag);
extern void Ov107_BuildAndSendUpdate(int obj, int effect, int kind, Vec3 *pos);
extern int RandNextScaled(int bound);
extern void SetIndexedSlot(int node, int slot, void *cb);

void Ov178_DashTick(int node)
{
    int *state = *(int **)(node + 4);
    Vec3 dir;
    Vec4 sphere;
    Vec3 push;
    int hits[4];
    Vec3 at;
    int n;
    int i;
    unsigned int mask;

    state[0x12] += *(int *)(*(int *)node + 0x2c);
    *(Vec3 *)(state + 8) = *(Vec3 *)(state + 0xe);
    n = 0;
    if (state[0x12] <= 0x2fd0) {
        VEC_Normalize((Vec3 *)(state + 0xe), &dir);
        ScaleVec3Fx12(0x600, &dir, &push);
        sphere = *(Vec4 *)(*state + 0x74);
        n = Ov107_CollectSphereOverlaps(*state, &sphere, hits);
        for (i = 0; i < n; i++) {
            mask = (1 << *(unsigned short *)(hits[i] + 2)) & 0xff;
            if ((*(unsigned char *)((char *)state + 0x86) & mask) == 0) {
                if (Ov107_InvokeHitCallback(hits[i], *state, *state, 0, &push, 0) != 0) {
                    VEC_Add((Vec3 *)state[2], &push, &at);
                    func_ov107_020c0b90(*state, 4, at, 0);
                    *(unsigned char *)((char *)state + 0x86) |= mask;
                    Ov107_BuildAndSendUpdate(*state, 0x143, 7, &at);
                }
            }
        }
    }
    if (*(signed char *)(*state + 0x1c7) != -1) {
        return;
    }
    if (*(unsigned char *)(state[1] + 0xad) != 0 && n == 0) {
        return;
    }
    if (RandNextScaled(5) == 0) {
        *(unsigned char *)(*state + 0x1c7) = 6;
        SetIndexedSlot(node, *(signed char *)(node + 0x20), 0);
    } else {
        *(unsigned char *)(*state + 0x1c7) = 5;
        SetIndexedSlot(node, *(signed char *)(node + 0x20), 0);
    }
}
