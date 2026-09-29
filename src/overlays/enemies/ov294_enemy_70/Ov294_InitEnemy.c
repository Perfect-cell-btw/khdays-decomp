/* Initialises the enemy actor: installs its handlers and camera, creates its model and attach slot,
 * and requests its resources. */

#include "nitro/types.h"
#include "game/enemy_common.h"

struct v3 {
    int a;
    int b;
    int c;
};

struct Work4 {
    struct v3 vec;
    int d;
};

struct Obj {
    char pad00[0x08];
    void (*fn08)(void);
    void (*fn0c)(void);
    char pad10[0x20];
    void (*fn30)(void);
    char pad34[0x30];
    int cam[4];
    char pad74[0x28];
    void *p9c;
    char padA0[0xA4];
    char pool144[0x6A];
    u16 flags1ae;
    char pad1B0[0x19];
    u8 state1c9;
    char pad1CA[0x06];
    void (*fn1d0)(void);
    char pad1D4[0x58];
    char pool22c[0x158];
    char *p384;
    int *p388;
    int pad38c;
    int p390;
};

extern struct v3 data_02041dc8;

extern void Ov294_OnDespawn(void);
extern void Ov294_BroadcastTransform(void);
extern void Ov294_CreateRegistryEntryForActor(void);
extern void Ov294_TickStaggerAndFlipFacing(void);

extern char *CreateSubitemInstance0xB4(void *);
extern void RegisterSubscriberSlot(void *, void *);
extern void Srt_SetTranslationXYZ(void *, int, int, int);
extern void SetSubitemState(void *, int, int, int);
extern void Ov107_Actor_SetAttachSlot(struct Obj *, int, int, int, int);
extern int *List_InsertSorted(void *, int, int);
extern int Ov107_CloneResourceTransform(void *);
extern void Res_RequestIdPair(int nId);

void Ov294_InitEnemy(struct Obj *arg0)
{
    struct Work4 work;
    int *slot;
    int result;

    arg0->fn08 = Ov294_OnDespawn;
    arg0->fn0c = Ov294_BroadcastTransform;
    arg0->fn30 = Ov294_CreateRegistryEntryForActor;
    arg0->fn1d0 = Ov294_TickStaggerAndFlipFacing;

    arg0->state1c9 = 2;

    arg0->cam[3] = 0x1200;
    arg0->cam[0] = 0;
    arg0->cam[1] = 0;
    arg0->cam[2] = 0;

    arg0->flags1ae |= 0x10;

    arg0->p384 = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)arg0, 0));
    RegisterSubscriberSlot(arg0->p9c, arg0->p384);
    Srt_SetTranslationXYZ(arg0->p384 + 4, 0, -0x1200, 0);
    SetSubitemState(arg0->p384, 0, 0, 1);
    SetSubitemState(arg0->p384, 4, 0, 1);
    Ov107_Actor_SetAttachSlot(arg0, 2, 2, 0, 0x2000);

    work.vec = data_02041dc8;
    work.d = 0x1200;

    arg0->p388 = List_InsertSorted(arg0->pool22c, 0x10, 0x64);
    *arg0->p388 = Ov107_CloneResourceTransform(&work);

    slot = List_InsertSorted(arg0->pool144, 4, 0x64);
    result = (*slot = Ov107_CloneResourceTransform(&work));
    arg0->p390 = result;

    Res_RequestIdPair(0x171);
}
