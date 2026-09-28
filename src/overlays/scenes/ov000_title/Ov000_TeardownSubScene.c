/* Tears the sub-scene down: releases the variant source, frees the three tile surfaces
 * (FreeAllListNodeSubBuffers), and frees the resource4b00 allocation if present, clearing its slot.
 */

#include "nitro/types.h"

typedef struct Ov000SubSceneContext {
    void *heapBuffers[4];
    u8 pad_0010[0x18];
    void *resource0028;
    u8 sceneBlock[0x4c];
    u8 objectList[0x4a88];
    void *resource4b00;
    u8 surface0[0x3c];
    u8 surface1[0x3c];
    u8 surface2[0x3c];
    u8 variantSource[0x0c];
} Ov000SubSceneContext;

extern Ov000SubSceneContext *volatile data_ov000_0205ac28;
extern void Ov000_FreeResourceRecordBuffer(void *resource);
extern void FreeAllListNodeSubBuffers(void *surface);
extern void NNSi_FndFreeFromDefaultHeap(void *allocation);
extern void Ov000_SweepElements(void *sceneBlock);
extern void Ov000_ReleaseThreeBuffers(void *sceneBlock);
extern void Ov000_DestroyAllListObjects(void *objectList);
extern void Ov000_ReleaseIfMarked(void *objectList);
extern void Ov000_DestroyObjectsAndRelease(void *objectList);
extern void ZeroHalfThenFree(void *resource);
extern void *G2S_GetBG0ScrPtr(void);
extern void *G2S_GetBG1ScrPtr(void);
extern void *G2S_GetBG2ScrPtr(void);
extern void *G2S_GetBG3ScrPtr(void);
extern void *G2S_GetBG0CharPtr(void);
extern void *G2S_GetBG1CharPtr(void);
extern void *G2S_GetBG2CharPtr(void);
extern void *G2S_GetBG3CharPtr(void);
extern void MIi_CpuClearFast(int value, void *destination, u32 size);

void Ov000_TeardownSubScene(void) {
    Ov000SubSceneContext *context = data_ov000_0205ac28;
    u8 i;

    Ov000_FreeResourceRecordBuffer(context->variantSource);
    FreeAllListNodeSubBuffers(data_ov000_0205ac28->surface0);
    FreeAllListNodeSubBuffers(data_ov000_0205ac28->surface1);
    FreeAllListNodeSubBuffers(data_ov000_0205ac28->surface2);

    {
        void *allocation = data_ov000_0205ac28->resource4b00;

        if (allocation != 0) {
            NNSi_FndFreeFromDefaultHeap(allocation);
            data_ov000_0205ac28->resource4b00 = 0;
        }
    }

    Ov000_SweepElements(context->sceneBlock);
    Ov000_ReleaseThreeBuffers(context->sceneBlock);
    Ov000_DestroyAllListObjects(context->objectList);
    Ov000_ReleaseIfMarked(context->objectList);
    Ov000_DestroyObjectsAndRelease(context->objectList);

    for (i = 0; i < 4; i++) {
        void *allocation = data_ov000_0205ac28->heapBuffers[i];

        if (allocation != 0) {
            NNSi_FndFreeFromDefaultHeap(allocation);
            data_ov000_0205ac28->heapBuffers[i] = 0;
        }
    }

    ZeroHalfThenFree(data_ov000_0205ac28->resource0028);

    MIi_CpuClearFast(0, G2S_GetBG0ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2S_GetBG1ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2S_GetBG2ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2S_GetBG3ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2S_GetBG0CharPtr(), 0x20);
    MIi_CpuClearFast(0, G2S_GetBG1CharPtr(), 0x20);
    MIi_CpuClearFast(0, G2S_GetBG2CharPtr(), 0x20);
    MIi_CpuClearFast(0, G2S_GetBG3CharPtr(), 0x20);

    data_ov000_0205ac28 = 0;
}
