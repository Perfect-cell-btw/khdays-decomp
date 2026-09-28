

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

extern void BgExtPltt_Upload (NNSG2dBGExtPlttSlot slot, const NNSG2dPaletteData * pPltData, const NNSG2dPaletteCompressInfo * pCmpInfo);
extern void func_02012a5c (NNSG2dBGSelect bg, const NNSG2dPaletteData * pPltData, const NNSG2dPaletteCompressInfo * pCmpInfo);
extern NNSG2dBGExtPlttSlot GetBGExtPlttSlot (NNSG2dBGSelect bg);

/* LoadBGPaletteSelect -- NitroSystem g2d_Screen.c: LoadBGPaletteSelect. */
void LoadBGPaletteSelect (NNSG2dBGSelect bg, BOOL bToExtPltt, const NNSG2dPaletteData * pPltData, const NNSG2dPaletteCompressInfo * pCmpInfo)
{

    if (bToExtPltt) {
        NNSG2dBGExtPlttSlot slot = GetBGExtPlttSlot(bg);
        BgExtPltt_Upload(slot, pPltData, pCmpInfo);
    } else {
        func_02012a5c(bg, pPltData, pCmpInfo);
    }
}
