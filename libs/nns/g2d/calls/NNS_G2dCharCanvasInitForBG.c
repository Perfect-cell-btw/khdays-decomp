

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

extern const NNSiG2dCharCanvasVTable data_02041a94;
extern void InitCharCanvas (NNSG2dCharCanvas * pCC, void * charBase, int areaWidth, int areaHeight, NNSG2dCharaColorMode colorMode, const NNSiG2dCharCanvasVTable * vtable, u32 param);

/* NNS_G2dCharCanvasInitForBG -- NitroSystem g2d_CharCanvas.c: NNS_G2dCharCanvasInitForBG. */
void NNS_G2dCharCanvasInitForBG (NNSG2dCharCanvas * pCC, void * charBase, int areaWidth, int areaHeight, NNSG2dCharaColorMode colorMode)
{

    InitCharCanvas(
        pCC,
        charBase, areaWidth, areaHeight, colorMode,
        &data_02041a94, (unsigned int)areaWidth
        );
}
