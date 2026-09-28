#include "nitro/types.h"

/* Combatant/creature instance: only the fields this function touches. Same
 * type is used both for the "target" argument and for the payload each list
 * entry points at (both are creature instances; effects are matched by id). */
typedef struct Combatant {
    u16 flags;              /* +0x00 */
    u16 id;                 /* +0x02 */
    u8  pad04[0x40 - 0x04];
    int field_40;           /* +0x40 */
    u8  pad44[0x1c5 - 0x44];
    u8  field_1c5;           /* +0x1c5 */
    u8  pad1c6[0x218 - 0x1c6];
    short field_218;        /* +0x218 */
    short field_21a;        /* +0x21a */
} Combatant;

/* Opaque sorted-list entry (see List_RemoveByHandle.c / List_InsertSorted): its payload
 * slot holds the Combatant this effect belongs to. */
typedef struct EffectEntry {
    Combatant *owner;       /* +0x00 */
} EffectEntry;

typedef struct BlockList {
    void *reserved0;         /* +0x00 */
    void *head;               /* +0x04 */
    void *reserved8;           /* +0x08 */
    void *reservedc;            /* +0x0c */
    void *termPrev;               /* +0x10 */
    void *termNext;                 /* +0x14 */
    void *termAddr;                   /* +0x18 */
    void *termHandle;                   /* +0x1c */
    int count;                            /* +0x20 */
    void *cur;                              /* +0x24 */
} BlockList;                                          /* size 0x28 */

typedef void (*ResetCallback)(void *self, int arg);

typedef struct StatusNode {
    u16 flags;                /* +0x00 */
    u8 pad02[0x14 - 0x02];
    ResetCallback field_14;   /* +0x14 */
    u8 pad18[0x80 - 0x18];
    BlockList list80;          /* +0x80 */
    BlockList lista8;           /* +0xa8 */
    BlockList listd0;             /* +0xd0 */
} StatusNode;

extern EffectEntry *List_First(BlockList *list);
extern int          List_RemoveByHandle(BlockList *list, EffectEntry *handle);
extern EffectEntry *List_Next(BlockList *list);
extern void         Ov107_Region_UnlinkChild(void *self, Combatant *target);

/* Clamp v into [lo, hi]. The upper bound is unsigned: with a signed bound the
 * compiler proves the upper test dead when v and hi are the same field and
 * deletes it, while the ROM keeps that compare (a dead `cmp r1, r1`). The type
 * is inferred from that one fact. With lo >= 0 it behaves as a signed clamp.
 * Ov107_Spawner_Run clamps the same fields with the same routine. */
static inline int ClampRange(int v, int lo, unsigned int hi)
{
    if (v < lo)
        return lo;
    if (v > hi)
        return hi;
    return v;
}

void Ov107_Region_RemoveMember(void *self_, Combatant *target)
{
    StatusNode *self = self_;
    u16 flags = target->flags;
    EffectEntry *handle;

    if (flags & 0x40) {
        handle = List_First(&self->list80);
        if (handle != 0) {
            do {
                if (handle->owner->id == target->id) {
                    List_RemoveByHandle(&self->list80, handle);
                    break;
                }
                handle = List_Next(&self->list80);
            } while (handle != 0);
        }
    } else if (flags & 0x80) {
        handle = List_First(&self->lista8);
        if (handle != 0) {
            do {
                if (handle->owner->id == target->id) {
                    List_RemoveByHandle(&self->lista8, handle);
                    break;
                }
                handle = List_Next(&self->lista8);
            } while (handle != 0);
        }

        if (self->lista8.count == 0) {
            handle = List_First(&self->list80);
            if (handle != 0) {
                do {
                    Combatant *node = handle->owner;
                    node->field_21a = ClampRange(node->field_218, 0, node->field_218);
                    node->field_1c5 &= ~0xf;
                    handle = List_Next(&self->list80);
                } while (handle != 0);
            }

            if (self->field_14 != 0) {
                self->field_14(self, 0);
            }
        }
    } else if (flags & 2) {
        handle = List_First(&self->listd0);
        if (handle != 0) {
            do {
                if (handle->owner->id == target->id) {
                    List_RemoveByHandle(&self->listd0, handle);
                    handle->owner->field_40 &= ~4;
                    break;
                }
                handle = List_Next(&self->listd0);
            } while (handle != 0);
        }
    }

    Ov107_Region_UnlinkChild(self, target);
}
