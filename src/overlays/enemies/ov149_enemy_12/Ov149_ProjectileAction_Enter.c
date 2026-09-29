/* Projectile action enter step (Ghidra: Ov149_ProjectileAction_Enter).
 *
 * Posts tag update 4 on the owner, raises bit 0x40 of the actor flags at +0x1ae,
 * hands the canned 4-byte event record data_ov149_020d074c[1] to the owner's
 * notify callback at +0x24, starts anim 1 on the rig at +0x3cc, sets bit 0x40 in
 * the high byte of the status halfword at +0x60 and dispatches the next step.
 *
 * The same ROM, up to relocations, is shared with six siblings: ov141 020cd2b0,
 * ov142 020d0ef0, ov143 020d4b30, ov150 020d0ef4, ov151 020ce4f0 and ov152
 * 020d5d70.
 *
 * Codegen note on the two-halfword record copy. Written as a plain pair of
 * halfword assignments, mwcc merges the two stores and colours them last-first:
 * the last value takes the lowest free register and the first falls to r3,
 * giving `ldrh r3,[r2,#6] ; ldrh r0,[r2,#4]`. The ROM instead gives the first
 * value the lowest free register and lets the second reuse the pool base as it
 * dies. Reading the two halves through a char * cursor into named temporaries
 * and storing them through volatile lvalues keeps the merged emission but
 * restores the ROM's colouring:
 *
 *     ldrh r0, [r2, #6]
 *     ldrh r2, [r2, #4]
 *     strh r0, [sp, #2]
 *     strh r2, [sp]
 */

#include "nitro/types.h"
#include "game/actor.h"
#include "game/ai_task.h"
#include "game/enemy_common.h"

typedef struct Ov149State Ov149State;

typedef void (*Ov149Callback)(Ov149State *state, u16 *pair, int count);

struct Ov149State {
    Actor base;                  /* 0x000 */
    u8 pad38c[0x40];
    int field_03cc;                      /* +0x3cc */
};

typedef struct Ov149StateRef {
    Ov149State *state;                   /* +0x00 */
} Ov149StateRef;

typedef struct Ov149Node {
    AI_TASK_FIELDS(Ov149StateRef)
} Ov149Node;

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern u16 data_ov149_020d074c[4];
extern void Ov149_stTransformProjectilePose(void);

void Ov149_ProjectileAction_Enter(Ov149Node *node)
{
    Ov149StateRef *state_ref = node->pState;
    u16 buf[2];
    u16 *pp;
    Ov149Callback cb;

    Ov107_PostTagUpdate((Actor *)state_ref->state, 4, 0);
    state_ref->state->base.flags1ae |= 0x40;

    pp = buf;
    {
        char *src = (char *)data_ov149_020d074c;
        u16 high = *(u16 *)(src + 6);
        u16 low = *(u16 *)(src + 4);

        *(volatile u16 *)&pp[1] = high;
        *(volatile u16 *)&pp[0] = low;
    }

    cb = state_ref->state->base.pfnPostMessage;
    if (cb != 0) {
        cb(state_ref->state, pp, 4);
    }

    Ov107_StartAnim(state_ref->state->field_03cc, 1, 0);

    {
        u16 value = state_ref->state->base.flags60.raw;
        state_ref->state->base.flags60.raw =
            (u16)((value & ~0xff00) |
                  (((((unsigned int)value << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
    }

    SetIndexedSlot(node,
                  node->slot,
                  Ov149_stTransformProjectilePose);
}
