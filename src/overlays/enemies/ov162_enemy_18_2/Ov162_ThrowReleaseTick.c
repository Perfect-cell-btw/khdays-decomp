/* Ov162_ThrowReleaseTick: throw-release tick of the ov161 enemy (x2), ported from the matched ov202 sibling (radius = timer * 4 + 0x800, pushes raised to 0x1000, kind bit 0x20000, +0x60 bit 7 set at the end). */
/* Ov162_ThrowReleaseTick: ported from a matched sibling family (same shape, constants and offsets adjusted). */

/*
 * Coordinates are held in a one-value wrapper type (Fx32), a tentative
 * reconstruction of the original's coordinate type. Copying a wrapped value is
 * a struct copy, which mwcc keeps, and that is the ROM's unread stack copy of
 * the position.
 */

#include "nitro/types.h"
#include "game/ai_task.h"

typedef struct { int value; } Fx32;
typedef struct { Fx32 x, y, z; } FxVec;

struct Sphere {
    FxVec centre;
    int radius;
};

struct Msg {
    u16 h[7];
};

struct Flags60 {
    u16 lo : 8;
    u16 hi : 8;
};

struct ObjFlags60 {
    u16 lo : 8;
    u16 hi : 8;
};

struct ListNode {
    void *item;
    char pad04[4];
    u32 lo08 : 8;
    u32 hi08 : 24;
};

struct HitPacket {
    u32 flags00;
    FxVec normal;
    u32 field10;
    u32 field14;
    void *pPart;
    u8 bKind1c;
    u8 pad1d[3];
    u32 tail[3];
};

struct PushPacket {
    FxVec push;
    u8 bKind0c;
    u8 bKind0d;
    u16 pad0e;
    u32 field10;
    u32 field14;
    int field18;
};

struct State {
    char *pActor;
    char pad04[0x2c];
    int nTimer30;
    char pad34[0xc];
    FxVec *pPos40;
    char pad44[8];
    unsigned long long uMask4c;
};

struct Node {
    AI_TASK_FIELDS(struct State)
};

extern void VEC_Subtract(FxVec *a, FxVec *b, FxVec *ab);
extern void VEC_Add(FxVec *a, FxVec *b, FxVec *ab);
extern int VEC_Normalize(FxVec *out, FxVec *in);
extern void ScaleVec3Fx12(int scale, FxVec *in, FxVec *out);
extern struct ListNode *List_First(void *list);
extern struct ListNode *List_Next(void *list);
extern int Ov107_CollectSphereOverlaps(char *actor, struct Sphere *shape, void **out);
extern int Ov107_InvokeHitCallback(void *victim, char *a, char *b, int mode,
                               FxVec *push, int flags);
extern int Ov107_HitShape_TestSphere(void *part, struct Sphere *shape, int mode);
extern int Ov107_AiState_ApplyHit(void *obj, void *target, struct HitPacket *packet);
extern int Ov162_collectChildrenInBox(void *world, struct Sphere *shape, void **out);
extern int Ov002_DispatchNodeEvent(void *obj, struct PushPacket *packet);
extern void *memset(void *, int, unsigned long);
extern void SetIndexedSlot(struct Node *node, int slot, int arg);

extern const struct Msg data_ov162_020d10a0;
extern const struct Msg data_ov162_020d10bc;

static inline void ov131_packImpact(struct Msg *msg, FxVec *v)
{
    FxVec raw;

    raw.x = v->x;
    raw.y = v->y;
    raw.z = v->z;
    ((u8 *)msg)[5] = (u8)(((u32)raw.x.value >> 16 & 0x7f) | ((u32)raw.x.value >> 24 & 0x80));
    ((u8 *)msg)[6] = (u8)((u32)raw.x.value >> 8);
    ((u8 *)msg)[7] = (u8)raw.x.value;
    ((u8 *)msg)[8] = (u8)(((u32)raw.y.value >> 16 & 0x7f) | ((u32)raw.y.value >> 24 & 0x80));
    ((u8 *)msg)[9] = (u8)((u32)raw.y.value >> 8);
    ((u8 *)msg)[10] = (u8)raw.y.value;
    ((u8 *)msg)[11] = (u8)(((u32)raw.z.value >> 16 & 0x7f) | ((u32)raw.z.value >> 24 & 0x80));
    ((u8 *)msg)[12] = (u8)((u32)raw.z.value >> 8);
    ((u8 *)msg)[13] = (u8)raw.z.value;
}

static inline void ov131_emitChildEvent(struct Msg *msg, FxVec *v)
{
    ov131_packImpact(msg, v);
}

static inline void ov131_scanVictims(struct State *st, struct Sphere *shape,
                                     void **aVictims, FxVec *vDir,
                                     FxVec *vPush, FxVec *vImpact, struct Msg *msgA)
{
    struct Msg tmplA;
    long nHits;
    long i;
    int id;
    void (*pfnHook)(char *, struct Msg *, int);

    nHits = Ov107_CollectSphereOverlaps(st->pActor, shape, aVictims);
    i = 0;
    if (nHits > 0) {
        tmplA = data_ov162_020d10bc;
        do {
            id = *(u16 *)((char *)aVictims[i] + 2);
            if ((st->uMask4c >> id & 1) == 0) {
                VEC_Subtract((FxVec *)((char *)aVictims[i] + 0x74), &shape->centre, vDir);
                VEC_Normalize(vDir, vDir);
                ScaleVec3Fx12(0x800, vDir, vPush);
                vPush->y.value = 0x1000;
                if (Ov107_InvokeHitCallback(aVictims[i], st->pActor, st->pActor, 1,
                                        vPush, 0) != 0) {
                    *msgA = tmplA;
                    ScaleVec3Fx12(shape->radius, vDir, vImpact);
                    VEC_Add(&shape->centre, vImpact, vImpact);
                    ov131_packImpact(msgA, vImpact);
                    pfnHook = *(void (**)(char *, struct Msg *, int))(st->pActor + 0x24);
                    if (pfnHook != 0) {
                        (*pfnHook)(st->pActor, msgA, 0xe);
                    }
                    id = *(u16 *)((char *)aVictims[i] + 2);
                    st->uMask4c = st->uMask4c | (unsigned long long)1 << id;
                }
            }
            i++;
        } while (i < nHits);
    }
}

void Ov162_ThrowReleaseTick(struct Node *node)
{
    struct State *st;
    void *world;
    void *aVictims[4];
    struct Sphere shape;
    FxVec vDir;
    FxVec vPush;
    FxVec vImpact;
    struct Msg msgA;
    struct ListNode *ln;
    struct ListNode *part;
    char *obj;
    void (*pfnHook)(char *, struct Msg *, int);
    int nHits;
    int i;
    int id;
    int timer;

    st = node->pState;
    world = *(void **)(st->pActor + 4);
    shape.centre = *st->pPos40;
    shape.radius = st->nTimer30 * 4 + 0x800;

    ov131_scanVictims(st, &shape, aVictims, &vDir, &vPush, &vImpact, &msgA);

    ln = List_First((char *)world + 0x80);
    obj = ln == 0 ? 0 : (char *)ln->item;
    while (obj != 0) {
        id = *(u16 *)(obj + 2);
        if ((st->uMask4c >> id & 1) == 0 &&
            obj != st->pActor && (((struct ObjFlags60 *)(obj + 0x60))->lo & 1) != 0 &&
            (*(u16 *)(obj + 0x1ac) & 7) == 0) {
            part = List_First(obj + 0x22c);
            while (part != 0) {
                if ((part->lo08 & 1) != 0 &&
                    Ov107_HitShape_TestSphere(part->item, &shape, 0) != 0) {
                    struct HitPacket packet = {0};
                    VEC_Subtract((FxVec *)(obj + 0x74), &shape.centre, &vDir);
                    VEC_Normalize(&vDir, &vDir);
                    ScaleVec3Fx12(0x800, &vDir, &vPush);
                    packet.flags00 = (u16)(packet.flags00 & 0xffff0000 | 4 |
                                          0x2000) | 0x20000;
                    packet.normal = vPush;
                    packet.field10 = packet.field10 & 0xffff0000 |
                                     *(u16 *)(st->pActor + 0x296);
                    packet.field14 = packet.field14 & 0xffff0000 |
                                     (*(u32 *)(st->pActor + 0x258) & 0xffff);
                    packet.pPart = part;
                    packet.bKind1c = 100;
                    if (Ov107_AiState_ApplyHit(obj, *(void **)(st->pActor + 0x25c),
                                            &packet) != 0) {
                        id = *(u16 *)(obj + 2);
                        st->uMask4c = st->uMask4c | (unsigned long long)1 << id;
                        break;
                    }
                }
                part = List_Next(obj + 0x22c);
            }
        }
        ln = List_Next((char *)world + 0x80);
        obj = ln == 0 ? 0 : (char *)ln->item;
    }

    void *aChildren[4];

    nHits = Ov162_collectChildrenInBox(*(void **)((char *)world + 0x7c), &shape, aChildren);
    i = 0;
    if (nHits > 0) {
        do {
            struct PushPacket push = {0};
            FxVec vDir2;
            FxVec vImpact2;
            struct Msg msgB;
            struct Msg tmplB;
            tmplB = data_ov162_020d10a0;
            VEC_Subtract((FxVec *)((char *)aChildren[i] + 0x2c), &shape.centre, &vDir2);
            VEC_Normalize(&vDir2, &vDir2);
            ScaleVec3Fx12(0x800, &vDir2, &push.push);
            push.bKind0c = 0xff;
            push.bKind0d = 2;
            push.field10 = *(u16 *)(st->pActor + 0x296);
            push.field14 = 4;
            push.field18 = 1 << *(u8 *)(st->pActor + 0x294);
            if (Ov002_DispatchNodeEvent(*(void **)(*(char **)((char *)aChildren[i] + 0x28) + 0x158),
                                    &push) != 0) {
                msgB = tmplB;
                ScaleVec3Fx12(shape.radius, &vDir2, &vImpact2);
                VEC_Add(&shape.centre, &vImpact2, &vImpact2);
                ov131_emitChildEvent(&msgB, &vImpact2);
                pfnHook = *(void (**)(char *, struct Msg *, int))(st->pActor + 0x24);
                if (pfnHook != 0) {
                    (*pfnHook)(st->pActor, &msgB, 0xe);
                }
            }
            i++;
        } while (i < nHits);
    }

    timer = st->nTimer30 + *(int *)((char *)node->pList + 0x2c);
    st->nTimer30 = timer;
    if (timer >= 0x1000) {
        u16 *hw = (u16 *)(st->pActor + 0x60);
        unsigned int h = *hw;
        *hw = h & ~0xff00 | (((((u32)h << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10);
        ((struct Flags60 *)(st->pActor + 0x60))->hi =
            ((struct Flags60 *)(st->pActor + 0x60))->hi & ~1;
        {
            u16 *hw2 = (u16 *)(st->pActor + 0x60);
            unsigned int h2 = *hw2;
            *hw2 = h2 & ~0xff00 | (((((u32)h2 << 0x10) >> 0x18 | 0x80) << 0x18) >> 0x10);
        }
        *(u8 *)(st->pActor + 0x1c7) = 3;
        SetIndexedSlot(node, node->slot, 0);
    }
}
