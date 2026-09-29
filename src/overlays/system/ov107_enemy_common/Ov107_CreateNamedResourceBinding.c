/* Creates a joint binding: a sub-item instance tracking the joint's motion, bound to the named
 * resource. */

#include "nitro/types.h"
#include "game/enemy_common.h"
#include "game/engine.h"

extern void *CallocInstance(u32 size);
extern void *CreateSubitemInstance0xB4(void *arg0);

typedef struct Ov107_9e50_Inner {
    char pad[0x6c];
    void *field_6c;
    char pad2[0x84 - 0x70];
    void *field_84;
} Ov107_9e50_Inner;

typedef struct Ov107_9e50 {
    u16 field_00;
    char pad[0x3a];
    Ov107_9e50_Inner *field_3c;
} Ov107_9e50;

void *Ov107_CreateNamedResourceBinding(int a, const void *b)
{
    Ov107_9e50 *self = (Ov107_9e50 *)CallocInstance(0x40);
    self->field_3c = (Ov107_9e50_Inner *)CreateSubitemInstance0xB4((void *)a);
    self->field_3c->field_6c = (void *)Ov107_TrackJointMotion;
    self->field_3c->field_84 = self;
    RefreshObjectCallbacks((int *)self->field_3c, 0);
    self->field_00 = (u16)FindResourceIndexByName(self->field_3c, (void *)b);
    return self;
}
