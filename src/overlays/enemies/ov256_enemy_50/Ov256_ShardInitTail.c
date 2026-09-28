/* Constructor tail of an ov256 shard: installs its handlers (+8 020d04f4, +0xc 020d0510, +0x30
 * 020d0560, +0x1d0 hit reaction 020d05bc), sets bits 1-2 and 6 of the +0x60 high byte and bit 2 of
 * +0x1ae, +0x70 = 0xa00, +0x54 / +0x58 clear; its model (+0x384) loads from the +0x398 owner's kit
 * entry 0x53, registers with the +0x9c scene and plays tracks 0-2 looped, the +0xa0 pose scales 2.0 and
 * a placement goes into a +0x22c pool slot at +0x388 (bit 1 set). */

#include "nitro/types.h"

typedef struct { unsigned f : 8; } B8;

extern int Ov107_PackTextureHandle(char *self, int kind);
extern int CreateSubitemInstance0xB4(int item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void SetSubitemState(int model, int track, int pose, int flag);
extern void Srt_SetScaleUniform(void *srt, int scale);
extern int *List_InsertSorted(void *pool, int elementSize, int capacity);
extern int Ov107_CloneResourceTransform(void *placement);
extern void Ov256_OnDespawn(void);
extern void Ov256_TickAndSyncModelXform(void);
extern void Ov256_Shard_CreateAiTask(void);
extern void Ov256_HelperHitReaction(void);

void Ov256_ShardInitTail(char *self)
{
    char *owner = *(char **)(self + 0x398);

    *(void **)(self + 8) = Ov256_OnDespawn;
    *(void **)(self + 0xc) = Ov256_TickAndSyncModelXform;
    *(void **)(self + 0x30) = Ov256_Shard_CreateAiTask;
    *(void **)(self + 0x1d0) = Ov256_HelperHitReaction;
    {
        u16 hw = *(u16 *)(self + 0x60);
        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x46) << 0x18) >> 0x10);
    }
    *(u16 *)(self + 0x1ae) |= 4;
    *(int *)(self + 0x70) = 0xa00;
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x58) = 0;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(owner, 0x53));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    SetSubitemState(*(int *)(self + 0x384), 0, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 2, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 1, 0, 1);
    Srt_SetScaleUniform(self + 0xa0, 0x2000);
    *(int **)(self + 0x388) = List_InsertSorted(self + 0x22c, 0x10, 100);
    **(int **)(self + 0x388) = Ov107_CloneResourceTransform(self + 0x64);
    ((B8 *)(*(char **)(self + 0x388) + 8))->f |= 2;
}
