/*
 * Box sweep of the ov191 enemy (x3: ov191/192/193). Builds an ov107 box query at *aim with the
 * world axes X/Z/Y and a half extent of 3.0 x len (fx64c -> fx32 rounding), collects up to
 * four actors in it and, for every actor whose kind bit is not yet in the state's +0x39 bit-1
 * mask, pushes it away along the flattened (y = 0x100) direction from the aim point at 0x800
 * through the ov107 hit hook (kind 1). A push that lands delivers a kind-5 / cmd-1 position
 * message with the actor's +0x190 position straight to the owner's +0x24 message handler,
 * marks the kind in the mask and fires reaction 0x53 with an unset position.
 *
 * Codegen notes: the message template is copied once into a local (tmpl) and per hit into msg
 * (an intra-struct copy reschedules the halfword loop); the packed position is mirrored into a
 * volatile VecFx32 (the stores survive and sink under the next load, x lands in lr); `n = 0` under
 * opt_dead_assignments off only orders the counter/count webs (i -> r4, n -> r5).
 */
#pragma opt_dead_assignments off

#include "nitro/types.h"
#include "nitro/fx_types.h"

typedef struct { u8 hi, mid, lo; } Fx24;   /* sign + 23-bit magnitude, big-endian */

typedef struct {
    u16 id;             /* +0x0 */
    u8 kind;            /* +0x2 */
    u8 cmd;             /* +0x3 */
    u8 flag;            /* +0x4 */
    Fx24 pos[3];        /* +0x5 */
} PosMsg;

struct BoxQuery {
    VecFx32 vCenter;
    VecFx32 vAxisX;
    VecFx32 vAxisZ;
    VecFx32 vAxisY;
    int nExtent;
    int bFlag;
};

struct Ov191Actor {
    char pad000[0x24];
    void (*pfnMessage)(struct Ov191Actor *self, PosMsg *msg, int size);
    char pad028[0x4c];
    VecFx32 vPos74;
    char pad080[0x110];
    VecFx32 vPos190;
    char pad19c[0x18];
    u8 nKind1b4;
};

struct Ov191ActionState {
    struct Ov191Actor *pOwner;
    char pad004[0x35];
    u8 bFacing : 1;
    u8 bHitMask : 1;
};

extern int Ov107_CollectEntitiesTouchingDisc(struct Ov191Actor *owner, struct BoxQuery *query, struct Ov191Actor **out);
extern void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern int VEC_Normalize(const VecFx32 *a, VecFx32 *out);
extern void ScaleVec3Fx12(int scale, const VecFx32 *v, VecFx32 *out);
extern int Ov107_InvokeHitCallback(struct Ov191Actor *hit, struct Ov191Actor *a, struct Ov191Actor *b, int kind, VecFx32 *push, int z);
extern void Ov107_BuildAndSendUpdate(struct Ov191Actor *owner, u16 a, u16 id, VecFx32 *pos);
extern const VecFx32 data_02042258;
extern const VecFx32 data_02042264;
extern const VecFx32 data_02042270;
extern const PosMsg data_ov192_020d4b94;

static inline void PackFx24(Fx24 *dst, int v) {
    dst->hi = ((u32)v >> 16 & 0x7f) | ((u32)v >> 24 & 0x80);
    dst->mid = (u32)v >> 8;
    dst->lo = v;
}

void Ov192_BoxSweepPush(struct Ov191ActionState *state, long long len, const VecFx32 *aim)
{
    struct Ov191Actor *hits[4];
    struct BoxQuery query;
    VecFx32 push;
    VecFx32 fxPos;
    PosMsg msg;
    PosMsg tmpl;
    volatile VecFx32 pos;
    int i;
    int n = 0;
    int x;

    query.vCenter = *aim;
    query.vAxisX = data_02042270;
    query.vAxisZ = data_02042258;
    query.vAxisY = data_02042264;
    query.nExtent = (int)((len * 0x3000 + 0x80000000LL) >> 32);
    query.bFlag = 1;
    n = Ov107_CollectEntitiesTouchingDisc(state->pOwner, &query, hits);
    i = 0;
    if (n > 0) {
        tmpl = data_ov192_020d4b94;
        do {
            if (((state->bHitMask >> hits[i]->nKind1b4) & 1) == 0) {
                VEC_Subtract(&hits[i]->vPos74, &query.vCenter, &push);
                push.y = 0;
                VEC_Normalize(&push, &push);
                push.y = 0x100;
                ScaleVec3Fx12(0x800, &push, &push);
                if (Ov107_InvokeHitCallback(hits[i], state->pOwner, state->pOwner, 1, &push, 0) != 0) {
                    msg = tmpl;
                    x = hits[i]->vPos190.x;
                    PackFx24(&msg.pos[0], x);
                    pos.x = x;
                    x = hits[i]->vPos190.y;
                    PackFx24(&msg.pos[1], x);
                    pos.y = x;
                    x = hits[i]->vPos190.z;
                    PackFx24(&msg.pos[2], x);
                    pos.z = x;
                    if (state->pOwner->pfnMessage != 0) {
                        state->pOwner->pfnMessage(state->pOwner, &msg, 0xe);
                    }
                    state->bHitMask = (u8)((1 << hits[i]->nKind1b4) | state->bHitMask);
                    Ov107_BuildAndSendUpdate(state->pOwner, 0, 0x53, &fxPos);
                }
            }
            i++;
        } while (i < n);
    }
}
