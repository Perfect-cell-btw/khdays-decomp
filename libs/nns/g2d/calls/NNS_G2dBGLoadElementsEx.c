

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

extern void func_02012e1c (NNSG2dBGSelect bg, const NNSG2dPaletteData * pPltData, const NNSG2dScreenData * pScnData, const NNSG2dPaletteCompressInfo * pCmpInfo);
extern void LoadBGCharacter (NNSG2dBGSelect bg, const NNSG2dCharacterData * pChrData, const NNSG2dCharacterPosInfo * pPosInfo);
extern void BgCharVram_Upload (NNSG2dBGSelect bg, const NNSG2dScreenData * pScnData);

/* NNS_G2dBGLoadElementsEx -- NitroSystem g2d_Screen.c: NNS_G2dBGLoadElementsEx. */
void NNS_G2dBGLoadElementsEx (NNSG2dBGSelect bg, const NNSG2dScreenData * pScnData, const NNSG2dCharacterData * pChrData, const NNSG2dPaletteData * pPltData, const NNSG2dCharacterPosInfo * pPosInfo, const NNSG2dPaletteCompressInfo * pCmpInfo)
{

    if (pPltData != NULL && pScnData != NULL) {
        func_02012e1c(bg, pPltData, pScnData, pCmpInfo);
    }
    if (pChrData != NULL) {
        LoadBGCharacter(bg, pChrData, pPosInfo);
    }
    if (pScnData != NULL) {
        BgCharVram_Upload(bg, pScnData);
    }
}
