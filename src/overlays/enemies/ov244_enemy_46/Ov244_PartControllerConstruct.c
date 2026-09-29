/* Constructor of the ov244 enemy's summoned part controller. Installs its handlers (+8, +0xc, +0x1c
 * message, +0x30 update), sets bits 1-3, 5 and 6 of the +0x60 high byte and bits 2-3 of +0x1ae,
 * scale 1.5 at +0x70 and clears +0x54; builds the +0x388 part (pose 0x2e of the owner's +0x384
 * pool, subscribed to +0x9c) with channels 0, 1, 2 and 4 bound to (0, 1), then the three hidden
 * sub-items of data_ov244_020d3774 into the +0x38c pair table. */

#include "nitro/types.h"
#include "game/enemy_common.h"

typedef void (*Callback)(void);
typedef struct { int id[3]; } IdTable3;
struct Pair { int res; int handle; };

extern void Ov244_PartController_Destroy(void);
extern void func_ov244_020d0e7c(void);
extern void Ov244_HandleRiderMessageB(void);
extern void Ov244_PartController_CreateAiTask(void);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void SetSubitemState(int item, int channel, int a, int b);
extern int CallocInstance(int size);
extern IdTable3 data_ov244_020d3774;

void Ov244_PartControllerConstruct(char *self)
{
    IdTable3 ids = data_ov244_020d3774;
    u16 hw;
    int i;

    *(Callback *)(self + 0x8) = Ov244_PartController_Destroy;
    *(Callback *)(self + 0xc) = func_ov244_020d0e7c;
    *(Callback *)(self + 0x1c) = Ov244_HandleRiderMessageB;
    *(Callback *)(self + 0x30) = Ov244_PartController_CreateAiTask;
    hw = *(u16 *)(self + 0x60);
    *(u16 *)(self + 0x60) = (hw & ~0xff00) |
        ((((((unsigned int)hw << 0x10) >> 0x18) | 0x6e) << 0x18) >> 0x10);
    *(u16 *)(self + 0x100 + 0xae) |= 0xc;
    *(int *)(self + 0x70) = 0x1800;
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x388) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)(*(int *)(self + 0x384)), 0x2e));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x388));
    SetSubitemState(*(int *)(self + 0x388), 0, 0, 1);
    SetSubitemState(*(int *)(self + 0x388), 1, 0, 1);
    SetSubitemState(*(int *)(self + 0x388), 2, 0, 1);
    SetSubitemState(*(int *)(self + 0x388), 4, 0, 1);
    *(int *)(self + 0x38c) = CallocInstance(0x18);
    for (i = 0; i < 3; i++) {
        ((struct Pair *)*(int *)(self + 0x38c))[i].res = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)(*(int *)(self + 0x384)), ids.id[i]));
        Ov107_EnqueueValue(self, ((struct Pair *)*(int *)(self + 0x38c))[i].res);
        *(int *)(((struct Pair *)*(int *)(self + 0x38c))[i].res + 0x5c) |= 2;
    }
}
