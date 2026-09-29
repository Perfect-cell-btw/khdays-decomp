/* Loads a model file (heap 0xf) into data_0204c20c[1], sets its textures up with the loader's
 * texture flag off (G3dRes_DefaultSetup), takes model 0 of its model set (NNS_G3dGetMdlSet /
 * NNS_G3dGetMdlByIdx, inlined) into data_0204c20c[0] and binds it (NNS_G3dMdlSetMdlLightEnableFlag). Returns 1. */
#pragma thumb on

#include "nitro/types.h"
#include "game/engine.h"

typedef struct {
    u8 revision;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 dummy_;
    u16 ofsEntry;
} NNSG3dResDict;

typedef struct {
    u16 sizeUnit;
    u16 sizeName;
    u8 data[4];
} NNSG3dResDictEntryHeader;

typedef struct {
    u32 header[2];
    NNSG3dResDict dict;
} NNSG3dResMdlSet;

extern void *Archive_LoadFile(const char *path, int heap);
extern NNSG3dResMdlSet *NNS_G3dGetMdlSet(void *file);   /* NNS_G3dGetMdlSet */
extern void NNS_G3dMdlSetMdlLightEnableFlag(void *mdl, int a, int b);
extern void *data_0204c20c[];

static inline void *GetResDataByIdx(const NNSG3dResDict *dict, u32 idx)
{
    if (dict != 0 && idx < dict->numEntry) {
        const NNSG3dResDictEntryHeader *hdr = (const NNSG3dResDictEntryHeader *)((u8 *)dict + dict->ofsEntry);

        return (void *)&hdr->data[idx * hdr->sizeUnit];
    }
    return 0;
}

static inline void *GetMdlByIdx(const NNSG3dResMdlSet *mdlSet, u32 idx)
{
    if (mdlSet) {
        const u32 *data = GetResDataByIdx(&mdlSet->dict, idx);

        if (data) {
            return (u8 *)mdlSet + *data;
        }
    }
    return 0;
}

int ModelFile_LoadFirst(const char *path)
{
    NNSG3dResMdlSet *mdlSet;

    data_0204c20c[1] = Archive_LoadFile(path, 0xf);
    InstallHandlerPairByFlag(0);
    G3dRes_DefaultSetup(data_0204c20c[1]);
    InstallHandlerPairByFlag(1);
    mdlSet = NNS_G3dGetMdlSet(data_0204c20c[1]);
    data_0204c20c[0] = GetMdlByIdx(mdlSet, 0);
    NNS_G3dMdlSetMdlLightEnableFlag(data_0204c20c[0], 0, 0);
    return 1;
}
