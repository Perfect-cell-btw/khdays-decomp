/* Throw windup of the ov156 enemy (and its byte-identical twin): re-acquires the target into
 * +0x18 (none requests sub-state 2 and ends the state) and aims the +0x14 heading at it; the
 * +0x30 rate is the frame delta * 30 / 5 and the +0x2c timer accumulates the delta. Once past
 * 0xccc (flagged in +0x38) the direction from the +0x39c item's +0x14 point to the target is
 * flattened and normalised, reaction 0x13d mode 4 fires at that point and the first of the two
 * +0x3a4 items whose +0x60 low bit is clear is launched along it (cdea4). When the +4 sub-node
 * goes idle the +0x34 cooldown is rolled between the actor's +0x224/+0x228 bounds, sub-state 2
 * is requested and the state ends. */
typedef struct { int x, y, z; } Vec3;
struct hw60 { unsigned short lo : 8, hi : 8; };

extern int Ov107_FindNearestObject(int actor, int mode);
extern void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *out);
extern int func_020050b4(int x, int z);
extern int VEC_Normalize(Vec3 *v, Vec3 *d);
extern void Ov107_BuildAndSendUpdate(int actor, int id, int mode, void *anchor);
extern void Ov157_RelayoutAndStoreVec(int item, void *from, Vec3 *dir);
extern int RandNextScaled(int bound);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov157_ThrowWindup(int *node)
{
    int *state = (int *)node[1];
    Vec3 d;
    Vec3 dir;
    int i;
    int lo;
    int span;

    state[6] = Ov107_FindNearestObject(*state, 0);
    if (state[6] == 0) {
        *(unsigned char *)(*state + 0x1c7) = 2;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    VEC_Subtract((Vec3 *)(state[6] + 0x190), (Vec3 *)state[2], &d);
    state[5] = func_020050b4(d.x, d.z);
    state[0xc] = *(int *)(*node + 0x2c) * 0x1e / 5;
    state[0xb] += *(int *)(*node + 0x2c);
    if (*(unsigned char *)(state + 0xe) == 0 && state[0xb] >= 0xccc) {
        *(unsigned char *)(state + 0xe) = 1;
        VEC_Subtract((Vec3 *)(state[6] + 0x74), (Vec3 *)(*(int *)(*state + 0x39c) + 0x14), &dir);
        dir.y = 0;
        VEC_Normalize(&dir, &dir);
        Ov107_BuildAndSendUpdate(*state, 0x13d, 4, (void *)(*(int *)(*state + 0x39c) + 0x14));
        for (i = 0; i < 2; i++) {
            if ((((struct hw60 *)((*(int **)(*state + 0x3a4))[i] + 0x60))->lo & 1) == 0) {
                Ov157_RelayoutAndStoreVec((*(int **)(*state + 0x3a4))[i], (void *)(*(int *)(*state + 0x39c) + 0x14), &dir);
                break;
            }
        }
    }
    if (*(unsigned char *)state[1] != 0) {
        return;
    }
    lo = *(int *)(*state + 0x224);
    span = *(int *)(*state + 0x228) - lo;
    if (span < 0) {
        span = -span;
    }
    state[0xd] = lo + RandNextScaled(span + 1);
    *(unsigned char *)(*state + 0x1c7) = 2;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
