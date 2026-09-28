

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/gfd.h"

extern NNSGfdFrmTexRegionState data_02042418[5 ];

/* NNS_GfdSetFrmTexVramState -- NitroSystem gfd_FrameTexVramMan.c: NNS_GfdSetFrmTexVramState. */
void NNS_GfdSetFrmTexVramState (const NNSGfdFrmTexVramState * pState)
{
    int i;

    for (i = 0; i < NNS_GFD_NUM_TEX_VRAM_REGION; i++)
    {
        data_02042418[i].head = pState->address[i * 2 + 0];
        data_02042418[i].tail = pState->address[i * 2 + 1];
    }
}
