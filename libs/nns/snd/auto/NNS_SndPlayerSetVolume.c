

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

inline BOOL NNS_SndHandleIsValid (const struct NNSSndHandle * handle)
{
    return handle->player != NULL ;
}

/* NNS_SndPlayerSetVolume -- NitroSystem player.c: NNS_SndPlayerSetVolume. */
void NNS_SndPlayerSetVolume (NNSSndHandle * handle, int volume)
{

    if (!NNS_SndHandleIsValid(handle)) return;

    handle->player->extVolume = (u8)volume;
}
