/* Ov253_RebuildCarriedLists -- rebuild the two carried work lists (+0x388 for the +0x384 owner and
 * +0x390 for the +0x38c owner): each is reset and cleared, seeded from the owner's +0x88 model,
 * given the ov107 pose picked by `idx` from the data_ov253_020d4894 / data_ov253_020d48c8
 * tables, then the owner list is re-initialised and finalised with `flag`. */

#include "game/enemy_common.h"

struct Ov253PoseTable { int w[13]; };

extern void FreeAllResourceTables(int list);
extern void MI_CpuFill8(void *dst, int val, int size);
extern void NNS_G3dRenderObjInit(int a, int b);
extern void Snd_RegisterSeqAndBind(int list, int owner, int pose, int d);
extern void MainBlob_ResetSlotRows(int owner, int list);
extern void SetSubitemState(int owner, int b, int c, int flag);
extern const struct Ov253PoseTable data_ov253_020d4894;
extern const struct Ov253PoseTable data_ov253_020d48c8;

typedef struct Ov253Carry {
    char pad000[0x384];
    int ownerA;         /* +0x384 */
    int listA;          /* +0x388 */
    int ownerB;         /* +0x38c */
    int listB;          /* +0x390 */
} Ov253Carry;     /* field access, not self + offset: it keeps the IR small enough that the
                     * last call's arguments are still scheduled, as in the ROM */

void Ov253_RebuildCarriedLists(Ov253Carry *self, int idx, int flag) {
    struct Ov253PoseTable tableA = data_ov253_020d4894;
    struct Ov253PoseTable tableB = data_ov253_020d48c8;
    int model;

    FreeAllResourceTables(self->listA);
    MI_CpuFill8((void *)self->listA, 0, 0x24);
    model = *(int *)(self->ownerA + 0x88);
    NNS_G3dRenderObjInit(model + 0x20, *(int *)(model + 0x78));
    Snd_RegisterSeqAndBind(self->listA, model, Ov107_PackTextureHandle((char *)((int)self), tableA.w[idx]), 0xc);
    MainBlob_ResetSlotRows(self->ownerA, self->listA);
    SetSubitemState(self->ownerA, 0, 0, flag);

    FreeAllResourceTables(self->listB);
    MI_CpuFill8((void *)self->listB, 0, 0x24);
    model = *(int *)(self->ownerB + 0x88);
    NNS_G3dRenderObjInit(model + 0x20, *(int *)(model + 0x78));
    Snd_RegisterSeqAndBind(self->listB, model, Ov107_PackTextureHandle((char *)((int)self), tableB.w[idx]), 0xc);
    MainBlob_ResetSlotRows(self->ownerB, self->listB);
    SetSubitemState(self->ownerB, 0, 0, flag);
}
