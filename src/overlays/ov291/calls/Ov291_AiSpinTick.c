/* Tracks the part offset, posts updates 0x16f/4 and /5 as the spin crosses 0x6000/0xc000; on anim
 * end queues 4 or 7. */

typedef unsigned char u8;
typedef unsigned short u16;

struct Elem16 {
    u8 pad00[0xc];
    int field_0c;
};

extern int Ov107_ActionResource_GetOffsetAndScale(int param_1, int param_2);
extern void Vec3TransformViaTempMtx(void *in_vec, int unused, void *out_vec);
extern int queryTableEntry(int param_1, int param_2);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void ScaleVec3Fx12(int factor, int *src, int *dst);
extern void SetIndexedSlot(int *a, int i, int v);

void Ov291_AiSpinTick(int *node)
{
    int *task = (int *)node[1];
    int local[3];
    int factor;
    int actor;
    u8 phase;

    actor = *(int *)task;
    factor = Ov107_ActionResource_GetOffsetAndScale(*(int *)(actor + 0x394), (int)local);

    actor = *(int *)task;
    Vec3TransformViaTempMtx((void *)local, actor + 0xa0, (void *)local);

    phase = *(u8 *)((char *)task + 0x28);
    if (phase == 0) {
        if (queryTableEntry(*(int *)(*(int *)task + 0x384), 0) >= 0x6000) {
            Ov107_BuildAndSendUpdate(*(int *)task, 0x16f, 4, task[3]);
            *(u8 *)((char *)task + 0x28) = 1;
        }
    } else if (phase == 1) {
        if (queryTableEntry(*(int *)(*(int *)task + 0x384), 0) >= 0xc000) {
            Ov107_BuildAndSendUpdate(*(int *)task, 0x16f, 5, task[3]);
            *(u8 *)((char *)task + 0x28) = 2;
        }
    } else if (phase == 2) {
        if (queryTableEntry(*(int *)(*(int *)task + 0x384), 0) < 0xc000) {
            *(u8 *)((char *)task + 0x28) = 0;
        }
    }

    ScaleVec3Fx12(factor, local, (int *)((char *)task + 0x10));
    task[7] = 0;

    if (*(u8 *)task[8] != 0) {
        return;
    }

    actor = *(int *)task;
    {
        int idx = task[9];
        struct Elem16 *arr = *(struct Elem16 **)(actor + 0x3a0);
        u16 val = (u16)arr[idx].field_0c;

        if (val == 1) {
            *(u8 *)(actor + 0x1c7) = 4;
        } else if (val == 2) {
            *(u8 *)(actor + 0x1c7) = 7;
        }
    }

    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
