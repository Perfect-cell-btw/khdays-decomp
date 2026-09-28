

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/gfd.h"

extern NNSGfdFrmTexRegionState data_02042418[5 ];

/* NNS_GfdGetFrmTexVramState -- NitroSystem gfd_FrameTexVramMan.c: NNS_GfdGetFrmTexVramState. */
void NNS_GfdGetFrmTexVramState (NNSGfdFrmTexVramState * pState)
{
    int i;

    for (i = 0; i < NNS_GFD_NUM_TEX_VRAM_REGION; i++)
    {
        pState->address[i * 2 + 0] = data_02042418[i].head;
        pState->address[i * 2 + 1] = data_02042418[i].tail;
    }
}
