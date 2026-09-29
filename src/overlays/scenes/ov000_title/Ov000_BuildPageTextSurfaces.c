/* Ov000_BuildPageTextSurfaces -- Scene 1: build the three text surfaces of the page.
 * Sibling of Ov000_SetupLogoTileSurfaces (same flow, this page's configs/globals): bind
 * the shared resource, open the message archive (data_ov000_0205aac4 name),
 * clear sub BG3 screen memory, point the three TileSurfaceCfg copies at the
 * resource storage and BG3 screen base, init the three 0x3c surfaces at
 * +0x4cc0/+0x4cfc/+0x4d38, then draw records 0..2 (header at 0x8e/0 selected,
 * two body lines at 0x10/0xf and 0x10/0x1e) and enqueue the three surfaces.
 * config1's first word is decremented when flag +0x4acc is set. */

#include "nitro/types.h"

typedef struct TileSurfaceCfg {
    u32 nUnk00;
    u8 unknown_04[0x14];
    void *pVramTarget;
    u32 nUnk1c;
    void *pPixels;
    u32 unknown_24;
} TileSurfaceCfg;

typedef struct Ov000TextSceneContext {
    u8 pad_0000[0x4acc];
    u8 flag_4acc;
    u8 pad_4acd[0x4afc - 0x4acd];
    u8 resourceStorage[8];
    void *resource;
    u8 pad_4b08[0x4cb4 - 0x4b08];
    u8 messageArchive[0x0c];
    u8 surface0[0x3c];
    u8 surface1[0x3c];
    u8 surface2[0x3c];
} Ov000TextSceneContext;

extern const TileSurfaceCfg data_ov000_0205a734;
extern const TileSurfaceCfg data_ov000_0205a75c;
extern const TileSurfaceCfg data_ov000_0205a784;
extern const char data_ov000_0205aac4[];
extern Ov000TextSceneContext *data_ov000_0205ac24;

extern void NNS_G2dFontInitUTF16(void *resource, void *sharedResource);
extern void Ov000_InitResourceRecord(void *object, const char *resourceName);
extern void *G2S_GetBG3ScrPtr(void);
extern void MIi_CpuClearFast(int value, void *destination, u32 size);
extern void TileSurface_InitAndUpload4bpp(void *surface, const TileSurfaceCfg *config);
extern void Obj_InvokeInnerVtable4(void *surface);
extern int *Ov000_GetVarRecordByIndex(void *object, int index);
extern void Ov000_DrawWithShadow(void *surface, int x, int y, int size, int *record, int sel);
extern void EnqueueObjGfxCommand(void *surface);

void Ov000_BuildPageTextSurfaces(void)
{
    TileSurfaceCfg config0 = data_ov000_0205a734;
    TileSurfaceCfg config1 = data_ov000_0205a75c;
    TileSurfaceCfg config2 = data_ov000_0205a784;
    int *record;

    if (data_ov000_0205ac24->flag_4acc != 0) {
        config1.nUnk00 -= 1;
    }

    NNS_G2dFontInitUTF16(data_ov000_0205ac24->resourceStorage,
                  data_ov000_0205ac24->resource);
    Ov000_InitResourceRecord(data_ov000_0205ac24->messageArchive,
                        data_ov000_0205aac4);
    MIi_CpuClearFast(0, G2S_GetBG3ScrPtr(), 0x800);

    config0.pPixels = data_ov000_0205ac24->resourceStorage;
    config0.pVramTarget = G2S_GetBG3ScrPtr();
    config2.pPixels = data_ov000_0205ac24->resourceStorage;
    config2.pVramTarget = G2S_GetBG3ScrPtr();
    config1.pPixels = data_ov000_0205ac24->resourceStorage;
    config1.pVramTarget = G2S_GetBG3ScrPtr();

    TileSurface_InitAndUpload4bpp(data_ov000_0205ac24->surface0, &config0);
    TileSurface_InitAndUpload4bpp(data_ov000_0205ac24->surface1, &config2);
    TileSurface_InitAndUpload4bpp(data_ov000_0205ac24->surface2, &config1);

    Obj_InvokeInnerVtable4(data_ov000_0205ac24->surface0);
    Obj_InvokeInnerVtable4(data_ov000_0205ac24->surface1);
    Obj_InvokeInnerVtable4(data_ov000_0205ac24->surface2);

    record = Ov000_GetVarRecordByIndex(data_ov000_0205ac24->messageArchive, 0);
    Ov000_DrawWithShadow(data_ov000_0205ac24->surface0, 0x8e, 0, 2, record, 1);
    record = Ov000_GetVarRecordByIndex(data_ov000_0205ac24->messageArchive, 1);
    Ov000_DrawWithShadow(data_ov000_0205ac24->surface1, 0x10, 0xf, 2, record, 0);
    record = Ov000_GetVarRecordByIndex(data_ov000_0205ac24->messageArchive, 2);
    Ov000_DrawWithShadow(data_ov000_0205ac24->surface0, 0x10, 0x1e, 4, record, 0);

    EnqueueObjGfxCommand(data_ov000_0205ac24->surface1);
    EnqueueObjGfxCommand(data_ov000_0205ac24->surface0);
    EnqueueObjGfxCommand(data_ov000_0205ac24->surface2);
}
