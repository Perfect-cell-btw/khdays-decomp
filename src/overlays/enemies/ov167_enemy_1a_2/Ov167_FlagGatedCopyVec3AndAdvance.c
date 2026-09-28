/* AI step: once the actor is active, places the tracking node 0x2000 above the actor's position
 * (+0xb0), records whether the context mode where it lands is 8, then makes the stored action
 * (+0x1c9) pending and clears the step handler. */

#include "nitro/fx_types.h"

struct Node {
    char pad0[0x60];
    unsigned short f60;
    char pad62[0x4e];
    VecFx32 fb0;
    char padbc[0x10b];
    signed char f1c7;
    char pad1c8;
    signed char f1c9;
};

struct Holder {
    struct Node *node;
    char pad4[0x10];
    VecFx32 f14;
    char pad20[0x68];
    int f88;
};

struct Obj {
    char pad0[4];
    struct Holder *holder;
    char pad8[0x18];
    signed char f20;
};

extern int Ov107_MoveNodeAndRelayout(int node, VecFx32 *v);
extern signed char Ov002_GetCtxModeByte(int x);
extern int SetIndexedSlot();

void Ov167_FlagGatedCopyVec3AndAdvance(struct Obj *this_) {
    struct Holder *h = this_->holder;
    struct Node *node = h->node;

    if (((unsigned)(node->f60 << 24) >> 24 & 1) == 0) return;

    h->f14 = node->fb0;
    h->f14.y += 0x2000;
    h->f88 = (Ov002_GetCtxModeByte(Ov107_MoveNodeAndRelayout((int)h->node, &h->f14)) == 8);
    node = h->node;
    node->f1c7 = node->f1c9;
    SetIndexedSlot(this_, this_->f20, 0);
}
