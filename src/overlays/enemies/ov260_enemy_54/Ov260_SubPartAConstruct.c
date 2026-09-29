/* Constructor of an ov260 sub-part (the pool at +0x390 is filled in by the creator). Installs the
 * handlers (+8, +0xc, +0x1c message, +0x30 update, +0x1d0 hit filter), sets bits 1-3 and 6 of the
 * +0x60 high byte and bit 2 of +0x1ae, scale 0.5 at +0x70, clears +0x54 / +0x58 and marks the
 * +0x9c parent (bit 2 of +0x5c); builds the +0x384 rig from pose 0x2a (subscribed to +0x9c) with
 * channels 0, 2, 4 and 1 bound to (0, 1) and re-inits it, builds the two hidden sub-items of its
 * id table into the +0x394 pairs, and reserves the +0x388 placement of the +0x64 pose on the
 * +0x22c pool (flag bit 1). */typedef unsigned short u16;
typedef void (*Callback)(void);
typedef struct { int id[2]; } IdTable2;
struct Pairs { char pad[0x394]; struct { int res; int handle; } pair[2]; };
typedef struct { unsigned f : 8; } B8;

extern void Ov260_Destroy(void);
extern void Ov260_TickAndSyncModelXform(void);
extern void Ov260_MessageHandler(void);
extern void Ov260_CreateRegistryEntryAndLink(void);
extern void Ov260_SubPartAHitFilter(void);
extern void *Ov107_PackTextureHandle(int pool, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void SetSubitemState(int item, int channel, int a, int b);
extern void RefreshObjectCallbacks(int item, int a);
extern void Ov107_EnqueueValue(char *self, int item);
extern int *List_InsertSorted(void *pool, int elementSize, int capacity);
extern int Ov107_CloneResourceTransform(void *placement);
extern IdTable2 data_ov260_020d2a80;

void Ov260_SubPartAConstruct(char *self)
{
    IdTable2 ids = data_ov260_020d2a80;
    int pool = *(int *)(self + 0x390);
    u16 hw;
    int i;

    *(Callback *)(self + 0x8) = Ov260_Destroy;
    *(Callback *)(self + 0xc) = Ov260_TickAndSyncModelXform;
    *(Callback *)(self + 0x1c) = Ov260_MessageHandler;
    *(Callback *)(self + 0x30) = Ov260_CreateRegistryEntryAndLink;
    *(Callback *)(self + 0x1d0) = Ov260_SubPartAHitFilter;
    hw = *(u16 *)(self + 0x60);
    *(u16 *)(self + 0x60) = (hw & ~0xff00) |
        ((((((unsigned int)hw << 0x10) >> 0x18) | 0x4e) << 0x18) >> 0x10);
    *(u16 *)(self + 0x100 + 0xae) |= 4;
    *(int *)(self + 0x70) = 0x800;
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x58) = 0;
    *(int *)(*(int *)(self + 0x9c) + 0x5c) |= 4;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(pool, 0x2a));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    SetSubitemState(*(int *)(self + 0x384), 0, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 2, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 4, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 1, 0, 1);
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    for (i = 0; i < 2; i++) {
        ((struct Pairs *)self)->pair[i].res = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(pool, ids.id[i]));
        Ov107_EnqueueValue(self, ((struct Pairs *)self)->pair[i].res);
        *(int *)(((struct Pairs *)self)->pair[i].res + 0x5c) |= 2;
    }
    *(int *)(self + 0x388) = (int)List_InsertSorted(self + 0x22c, 0x10, 100);
    **(int **)(self + 0x388) = Ov107_CloneResourceTransform(self + 0x64);
    ((B8 *)(*(int *)(self + 0x388) + 8))->f |= 2;
}
