struct Vec3 { int x, y, z; };

struct Node {
    char pad0[0x60];
    unsigned short f60;
    char pad62[0x4e];
    struct Vec3 fb0;
    char padbc[0x10b];
    signed char f1c7;
    char pad1c8;
    signed char f1c9;
};

struct Holder {
    struct Node *node;
    char pad4[0x10];
    struct Vec3 f14;
    char pad20[0x68];
    int f88;
};

struct Obj {
    char pad0[4];
    struct Holder *holder;
    char pad8[0x18];
    signed char f20;
};

extern int Ov107_MoveNodeAndRelayout(int node, struct Vec3 *v);
extern int Ov002_GetCtxModeByte(int x);
extern int SetIndexedSlot();

void Ov176_FlagGatedCopyVec3AndAdvance(struct Obj *this_) {
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
