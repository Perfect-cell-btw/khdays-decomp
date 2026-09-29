/* Construction of the ov223 enemy's item: installs the handlers (+8 020d4030, +0xc 020d405c,
 * +0x1c 020d4068, +0x20 020d4278, +0x24 020d42e0, +0x30 020d4808), raises bits 1-3 and 6 and
 * then bit 5 of the +0x60 high byte (the data_ov223_020d50f4 kind is copied to the stack
 * between the two writes), bits 2 and 4 of +0x1ae and bit 2 of the +0x9c parent's +0x5c, sets
 * +0x70 to 1 and clears +0x54/+0x58; builds the +0x384 item from pose 0x1a of the +0x38c pool
 * (channel 0 enabled), subscribes it to the parent and finalises it; builds the +0x398
 * sub-item from the saved kind and the +0x394 one from resource 0x20 entry 0x22 (both
 * registered on the actor, bit 1 of +0x5c raised), binds channels 0, 2 and 4 of the latter's
 * +0x88 track's +0xe0 block (0202accc), allocates the +0x390 ring (ov223 4e24) and clears
 * +0x388. */

#include "game/enemy_common.h"

extern int CreateSubitemInstance0xB4(int a);
extern void SetSubitemState(int obj, int mode, int a, int b);
extern void RegisterSubscriberSlot(int a, int obj);
extern void RefreshObjectCallbacks(int obj, int a);
extern int JointModel_New(int res, int n);
extern void BindAnimTrack(int track, int channel, int block, int flag);
extern int Ov223_CreateReactionTask(char *self);
extern void Ov223_Destroy_2(void);
extern void func_ov223_020d405c(void);   /* misnamed: an ov223 veneer to Ov107_ProcessObjectTick */
extern void Ov223_HandleMessage(void);
extern void Ov223_BroadcastEmpty(void);
extern void Ov223_PackPositionMessage(void);
extern void Ov223_CreateRegistryEntryAndLink(void);

struct Ov223Saved { int w; };
extern const struct Ov223Saved data_ov223_020d50f4;

void Ov223_ConstructItem(char *self) {
    int owner;
    unsigned short v;
    struct Ov223Saved saved;
    int sub;
    int *grip = (int *)(self + 0x394);     /* the +0x394 item slot, read back through this pointer */

    owner = *(int *)(self + 0x38c);
    *(void **)(self + 8) = (void *)Ov223_Destroy_2;
    *(void **)(self + 0xc) = (void *)func_ov223_020d405c;
    *(void **)(self + 0x1c) = (void *)Ov223_HandleMessage;
    *(void **)(self + 0x20) = (void *)Ov223_BroadcastEmpty;
    *(void **)(self + 0x24) = (void *)Ov223_PackPositionMessage;
    *(void **)(self + 0x30) = (void *)Ov223_CreateRegistryEntryAndLink;

    v = *(unsigned short *)(self + 0x60);
    *(unsigned short *)(self + 0x60) =
        (unsigned short)((v & ~0xff00)
                         | (((((unsigned int)v << 0x10) >> 0x18 | 0x4e) << 0x18) >> 0x10));

    saved = data_ov223_020d50f4;

    v = *(unsigned short *)(self + 0x60);
    *(unsigned short *)(self + 0x60) =
        (unsigned short)((v & ~0xff00)
                         | (((((unsigned int)v << 0x10) >> 0x18 | 0x20) << 0x18) >> 0x10));

    *(unsigned short *)(self + 0x1ae) |= 0x14;
    *(int *)(self + 0x70) = 1;
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x58) = 0;
    *(int *)(*(int *)(self + 0x9c) + 0x5c) |= 4;

    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)owner, 0x1a));
    SetSubitemState(*(int *)(self + 0x384), 0, 0, 1);
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);

    sub = *(int *)(self + 0x398) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)owner, saved.w));
    Ov107_EnqueueValue((char *)((int)self), sub);
    *(int *)(*(int *)(self + 0x398) + 0x5c) |= 2;

    sub = *grip = JointModel_New(Ov107_PackTextureHandle((char *)owner, 0x20), 0x22);
    Ov107_EnqueueValue((char *)((int)self), sub);
    *(int *)(*grip + 0x5c) |= 2;
    BindAnimTrack(*(int *)(*grip + 0x88), 0, *(int *)(*grip + 0x88) + 0xe0, 0);
    BindAnimTrack(*(int *)(*grip + 0x88), 2, *(int *)(*grip + 0x88) + 0xe0, 0);
    BindAnimTrack(*(int *)(*grip + 0x88), 4, *(int *)(*grip + 0x88) + 0xe0, 0);

    *(int *)(self + 0x390) = Ov223_CreateReactionTask((char *)self);
    *(int *)(self + 0x388) = 0;
}
