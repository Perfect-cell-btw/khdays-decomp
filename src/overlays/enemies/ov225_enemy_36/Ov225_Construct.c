/* Construction of the ov221 enemy's item: installs the handlers (+8 020d4218, +0xc 020d424c,
 * +0x1c 020d42b0, +0x30 020d443c), raises bit 5 and then bits 1-3 and 6 of the +0x60 high byte
 * (the data_ov225_020d50c8 kind is copied to the stack between the two writes), bit 2 of +0x1ae
 * and of the +0x9c parent's +0x5c, sets +0x70 to 1 and clears +0x54/+0x58, builds the +0x384
 * item from pose 0x1a of the +0x390 pool (channels 0, 2 and 4 enabled) and gives its +0x88 track's
 * +0x78 the rolling data_ov225_020d5134 slot (which then advances, wrapping to 3 at 0x1f);
 * a built item is subscribed to the parent and finalised. A non-negative saved kind builds the
 * +0x394 sub-item (registered on the actor, bit 1 of +0x5c raised). Finally a +0x22c list slot
 * takes the +0x64 pose as +0x388 with bit 1 of its +8 low byte raised, and +0x38c clears. */

#include "game/enemy_common.h"

typedef struct {
    unsigned f : 8;
} B8;

struct Ov221Saved { int w; };
struct RollingCounter { unsigned char value; };

extern int CreateSubitemInstance0xB4(int a);
extern void SetSubitemState(int obj, int mode, int a, int b);
extern void NNS_G3dMdlSetMdlPolygonID(int a, unsigned int b, unsigned int slot);
extern void RegisterSubscriberSlot(int a, int obj);
extern void RefreshObjectCallbacks(int obj, int a);
extern int List_InsertSorted(int a, int b, int c);
extern int Ov107_CloneResourceTransform(int a);
extern void Ov225_Projectile_Destroy(void);
extern void Ov225_Projectile_TickSyncXform(void);
extern void Ov225_CmdSpawnChild(void);
extern void Ov225_Projectile_CreateAiTask(void);
extern const struct Ov221Saved data_ov225_020d50c8;
extern struct RollingCounter data_ov225_020d5134;

void Ov225_Construct(char *self) {
    int owner;
    unsigned short v;
    struct Ov221Saved saved;

    owner = *(int *)(self + 0x390);
    *(void **)(self + 8) = (void *)Ov225_Projectile_Destroy;
    *(void **)(self + 0xc) = (void *)Ov225_Projectile_TickSyncXform;
    *(void **)(self + 0x1c) = (void *)Ov225_CmdSpawnChild;
    *(void **)(self + 0x30) = (void *)Ov225_Projectile_CreateAiTask;

    v = *(unsigned short *)(self + 0x60);
    *(unsigned short *)(self + 0x60) =
        (unsigned short)((v & ~0xff00)
                         | (((((unsigned int)v << 0x10) >> 0x18 | 0x20) << 0x18) >> 0x10));

    saved = data_ov225_020d50c8;

    v = *(unsigned short *)(self + 0x60);
    *(unsigned short *)(self + 0x60) =
        (unsigned short)((v & ~0xff00)
                         | (((((unsigned int)v << 0x10) >> 0x18 | 0x4e) << 0x18) >> 0x10));

    *(unsigned short *)(self + 0x1ae) |= 4;
    *(int *)(self + 0x70) = 1;
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x58) = 0;
    *(int *)(*(int *)(self + 0x9c) + 0x5c) |= 4;

    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)owner, 0x1a));
    SetSubitemState(*(int *)(self + 0x384), 0, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 2, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 4, 0, 1);
    NNS_G3dMdlSetMdlPolygonID(*(int *)(*(int *)(*(int *)(self + 0x384) + 0x88) + 0x78), 0,
                  data_ov225_020d5134.value);

    /* Stored, then re-read through the byte for the wrap test -- that is what pins the store
     * ahead of the compare, which is where the ROM puts it. */
    data_ov225_020d5134.value = data_ov225_020d5134.value + 1;
    if (data_ov225_020d5134.value >= 0x1f) {
        data_ov225_020d5134.value = 3;
    }

    if (*(int *)(self + 0x384) != 0) {
        RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
        RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    }

    if (saved.w >= 0) {
        *(int *)(self + 0x394) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)owner, saved.w));
        Ov107_EnqueueValue((char *)((int)self), *(int *)(self + 0x394));
        *(int *)(*(int *)(self + 0x394) + 0x5c) |= 2;
    }

    *(int *)(self + 0x388) = List_InsertSorted((int)(self + 0x22c), 0x10, 0x64);
    **(int **)(self + 0x388) = Ov107_CloneResourceTransform((int)(self + 0x64));
    ((B8 *)(*(int *)(self + 0x388) + 8))->f |= 2;
    *(int *)(self + 0x38c) = 0;
}
