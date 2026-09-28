

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

void SND_SetTrackPan(int playerNo, u32 trackBitMask, int pan);
inline BOOL NNS_SndHandleIsValid (const struct NNSSndHandle * handle)
{
    return handle->player != NULL ;
}

/* NNS_SndPlayerSetTrackPan -- NitroSystem player.c: NNS_SndPlayerSetTrackPan. */
void NNS_SndPlayerSetTrackPan (NNSSndHandle * handle, u16 trackBitMask, int pan)
{

    if (!NNS_SndHandleIsValid(handle)) return;

    SND_SetTrackPan(handle->player->playerNo, trackBitMask, pan);
}
