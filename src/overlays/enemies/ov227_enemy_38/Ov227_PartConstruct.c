/* Constructor of an ov227 part (spawned by the enemy, owner at +0x38c). Installs the handlers (+8,
 * +0x1c message, +0x30), sets bits 1/3/4/6 of the +0x60 high byte (0x5a), bit 2 of +0x1ae and the
 * +0x70 scale 0.63, clears +0x54/+0x58 and flags its +0x9c body (bit 2 of +0x5c); builds the +0x384
 * rig from the owner's pose 0x1e (subscribed to +0x9c, channels 0/2/4/1 looped, reset) and the two
 * sub-items of data_ov227_020d4b6c into the +0x390 pair table (registered, bit 1 of +0x5c). */
typedef struct { int id[2]; } IdPair;
struct Pair { int res; int handle; };
struct Ov227Part { char pad[0x390]; struct Pair pairs[2]; };

extern void *Ov107_PackTextureHandle(int owner, int kind);
extern int CreateSubitemInstance0xB4(void *res);
extern void RegisterSubscriberSlot(int list, int node);
extern void SetSubitemState(int obj, int channel, int a, int b);
extern void RefreshObjectCallbacks(int obj, int a);
extern void Ov107_EnqueueValue(char *self, int obj);
extern void Ov227_Actor_Destroy(void);
extern void Ov227_PartOnEffectMessage(void);
extern void Ov227_CreateRegistryEntryAndLink(void);
extern IdPair data_ov227_020d4b6c;

void Ov227_PartConstruct(char *self)
{
    IdPair ids = data_ov227_020d4b6c;
    int owner = *(int *)(self + 0x38c);
    unsigned short v;
    int i;

    *(void **)(self + 8) = (void *)Ov227_Actor_Destroy;
    *(void **)(self + 0x1c) = (void *)Ov227_PartOnEffectMessage;
    *(void **)(self + 0x30) = (void *)Ov227_CreateRegistryEntryAndLink;
    v = *(unsigned short *)(self + 0x60);
    *(unsigned short *)(self + 0x60) =
        (unsigned short)((v & ~0xff00) | (((((unsigned int)v << 0x10) >> 0x18 | 0x5a) << 0x18) >> 0x10));
    *(unsigned short *)(self + 0x1ae) |= 4;
    *(int *)(self + 0x70) = 0xa00;
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x58) = 0;
    *(int *)(*(int *)(self + 0x9c) + 0x5c) |= 4;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(owner, 0x1e));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    SetSubitemState(*(int *)(self + 0x384), 0, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 2, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 4, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 1, 0, 1);
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    for (i = 0; i < 2; i++) {
        Ov107_EnqueueValue(self, ((struct Ov227Part *)self)->pairs[i].res =
                                      CreateSubitemInstance0xB4(Ov107_PackTextureHandle(owner, ids.id[i])));
        *(int *)(((struct Ov227Part *)self)->pairs[i].res + 0x5c) |= 2;
    }
}
