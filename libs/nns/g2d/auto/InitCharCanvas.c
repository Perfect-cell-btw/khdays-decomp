

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

/* InitCharCanvas -- NitroSystem g2d_CharCanvas.c: InitCharCanvas. */
void InitCharCanvas (NNSG2dCharCanvas * pCC, void * charBase, int areaWidth, int areaHeight, NNSG2dCharaColorMode colorMode, const NNSiG2dCharCanvasVTable * vtable, u32 param)
{

    pCC->areaWidth = areaWidth;
    pCC->areaHeight = areaHeight;
    pCC->dstBpp = colorMode;
    pCC->charBase = charBase;
    pCC->vtable = vtable;
    pCC->param = param;
}
