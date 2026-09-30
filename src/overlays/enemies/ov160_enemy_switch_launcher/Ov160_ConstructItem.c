/* Construction of the ov160 enemy's item: installs the handlers (+8 020ceaf0, +0xc 020ceb20,
 * +0x1c 020ceb58, +0x30 020cec28, +0x1d0 020cebcc), raises bits 1-3 and 6 of the +0x60 high
 * byte, bit 2 of +0x1ae and of the +0x9c parent's +0x5c, sets +0x70 to 0x1000, builds the +0x384
 * item from pose 6 of the +0x38c pool (subscribed to the parent, scaled 0x2000, channels 0 and 2 enabled,
 * finalised), allocates the +0x390 block whose effect comes from the data_ov160_020cf7c4 pose
 * (registered on the actor, bit 1 of +0x5c raised), and links a +0x22c list slot to the +0x64
 * pose as +0x388 with bit 1 of its +8 low byte raised. */

#include "nitro/types.h"

struct Ov160Pose { int w; };
struct Ov160Byte8 { u32 lo : 8, rest : 24; };

extern void *Ov107_PackTextureHandle(int pool, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void Srt_SetScaleUniform(void *transform, int scale);
extern void SetSubitemState(int item, int channel, int a, int b);
extern void RefreshObjectCallbacks(int item, int a);
extern void *CallocInstance(int size);
extern void Ov107_EnqueueValue(char *self, int item);
extern int *List_InsertSorted(char *list, int stride, int max);
extern int Ov107_CloneResourceTransform(char *pose);
extern const struct Ov160Pose data_ov160_020cf7c4;
extern void Ov160_SubObject_Destroy(void);
extern void Ov160_TickAndSyncModelXform(void);
extern void Ov160_EventArmEmitterPayload(void);
extern void Ov160_CreateRegistryEntryAndLink(void);

void Ov160_ConstructItem(char *self)
{
    struct Ov160Pose pose = data_ov160_020cf7c4;

    *(void **)(self + 0x8) = Ov160_SubObject_Destroy;
    *(void **)(self + 0xc) = Ov160_TickAndSyncModelXform;
    *(void **)(self + 0x1c) = Ov160_EventArmEmitterPayload;
    *(void **)(self + 0x30) = Ov160_CreateRegistryEntryAndLink;
    {
        u16 hw = *(u16 *)(self + 0x60);
        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x4e) << 0x18) >> 0x10);
    }
    *(u16 *)(self + 0x100 + 0xae) |= 4;
    *(int *)(*(int *)(self + 0x9c) + 0x5c) |= 4;
    *(int *)(self + 0x70) = 0x1000;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(*(int *)(self + 0x38c), 6));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    Srt_SetScaleUniform((void *)(*(int *)(self + 0x384) + 4), 0x2000);
    SetSubitemState(*(int *)(self + 0x384), 0, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 2, 0, 1);
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    *(int **)(self + 0x390) = CallocInstance(8);
    **(int **)(self + 0x390) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(*(int *)(self + 0x38c), pose.w));
    Ov107_EnqueueValue(self, **(int **)(self + 0x390));
    *(int *)(**(int **)(self + 0x390) + 0x5c) |= 2;
    *(int **)(self + 0x388) = List_InsertSorted(self + 0x22c, 0x10, 0x64);
    **(int **)(self + 0x388) = Ov107_CloneResourceTransform(self + 0x64);
    ((struct Ov160Byte8 *)(*(int **)(self + 0x388) + 2))->lo |= 2;
}
