/* Registry task (0xc8) binding a node and a 44-byte body block; applies SetSubitemState for each
 * set bit of kind, then refreshes. */

#include "nitro/types.h"

typedef struct Blk44 { int w[11]; } Blk44; /* 44 bytes */

typedef struct Inner09a0 {
    char pad00[4];
    Blk44 body;              /* offset 4 .. 0x30 */
    char pad30[0x5c - 0x30];
    int flags;                /* offset 0x5c */
} Inner09a0;

typedef struct ObjType {
    Inner09a0 *field0;
    Blk44 *field4;
    u8 field8;
    u8 field9;
    char pad0a[0xc - 0xa];
    int field_c;
} ObjType;

extern int CreateRegistryEntry(int param_1, unsigned int param_2, unsigned int param_3,
                          int param_4, int param_5, int *param_6);
extern void SetSubitemState(Inner09a0 *a, u16 b, int c, int d);
extern void RefreshObjectCallbacks(Inner09a0 *ptr, int arg);
extern void Ov107_TaskTeardown_FlagOwner_2(void *a);
extern int Ov107_stAdvanceState_ccedc(int param_1);

int Ov107_CreateNodeBodyTask(int resource, int node, int kind, void *transform,
                         unsigned char e, int f)
{
    ObjType *object;
    int i;
    int id;

    id = CreateRegistryEntry(resource, 0xc8, 0x10, (int)Ov107_stAdvanceState_ccedc,
                        (int)Ov107_TaskTeardown_FlagOwner_2, (int *)&object);

    object->field0 = (Inner09a0 *)node;
    object->field4 = (Blk44 *)transform;

    object->field0->body = *object->field4;

    object->field8 = (u8)kind;
    object->field_c = f;
    object->field9 = (u8)e;

    object->field0->flags &= ~2;

    for (i = 0; i < 5; i++) {
        if (object->field8 & (1 << i))
            SetSubitemState(object->field0, (u16)i, object->field9, object->field_c);
    }

    RefreshObjectCallbacks(object->field0, 0);

    return id;
}
