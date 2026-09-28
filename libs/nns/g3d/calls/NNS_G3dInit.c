#include "nitro/types.h"
#include "nitro/os.h"
typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

#define offsetof(type, member) ((u32)&(((type *)0)->member))

typedef enum {
    GX_FIFOINTR_COND_DISABLE      = 0,
    GX_FIFOINTR_COND_UNDERHALF    = 1,
    GX_FIFOINTR_COND_EMPTY        = 2
} GXFifoIntrCond;
void G3X_Init(void);
extern void G3X_SetFifoIntrCond(GXFifoIntrCond cond);
static inline void G3X_SetFifoIntrCond (GXFifoIntrCond cond)
{
    (*( REGType32v *) (0x04000000 + 0x600)) = (((*( REGType32v *) (0x04000000 + 0x600)) & ~0xc0000000 ) |
                      (cond << 30 ));
}
void NNS_G3dGlbInit(void);

/* NNS_G3dInit -- NitroSystem util.c: NNS_G3dInit. */
void NNS_G3dInit (void)
{
    G3X_Init();

    NNS_G3dGlbInit();

    G3X_SetFifoIntrCond(GX_FIFOINTR_COND_EMPTY);
}
