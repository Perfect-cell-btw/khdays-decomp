/* Setup of the ov248 actor: installs the +8 tick (020d03cc), +0x1c message (020d03fc), +0x30 (020d0578)
 * and +0x34 release (020d0534) handlers, sets bits 1-3 of the +0x60 high byte and bits 2 and 4 of
 * +0x1ae, the +0x70 scale to 0.875, and builds the two +0x388 slot models from the +0x384 pool (kinds
 * from data_ov248_020d0c04), attached and hidden (bit 1 on their +0x5c). */

#include "nitro/types.h"

typedef void (*Callback)(void);
struct Slot { int model; int effect; };
struct Ov248Actor { char pad[0x388]; struct Slot slots[2]; };

extern void Ov248_Destroy_2(void);
extern void Ov248_ActorOnMessage(void);
extern void Ov248_CreateAiTask(void);
extern void Ov248_Release(void);
extern void *Ov107_PackTextureHandle(int pool, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern void Ov107_EnqueueValue(char *self, int item);
typedef struct { int w[2]; } KindTable;
extern const KindTable data_ov248_020d0c04;

void Ov248_Setup(char *self)
{
    KindTable kinds;
    int pool;
    int i;

    kinds = data_ov248_020d0c04;
    pool = *(int *)(self + 0x384);
    *(Callback *)(self + 0x8) = Ov248_Destroy_2;
    *(Callback *)(self + 0x1c) = Ov248_ActorOnMessage;
    *(Callback *)(self + 0x30) = Ov248_CreateAiTask;
    *(Callback *)(self + 0x34) = Ov248_Release;
    {
        u16 hw = *(u16 *)(self + 0x60);

        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0xe) << 0x18) >> 0x10);
    }
    *(u16 *)(self + 0x100 + 0xae) |= 0x14;
    *(int *)(self + 0x70) = 0xe00;
    for (i = 0; i < 2; i++) {
        ((struct Ov248Actor *)self)->slots[i].model = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(pool, kinds.w[i]));
        Ov107_EnqueueValue(self, ((struct Ov248Actor *)self)->slots[i].model);
        *(int *)(((struct Ov248Actor *)self)->slots[i].model + 0x5c) |= 2;
    }
}
