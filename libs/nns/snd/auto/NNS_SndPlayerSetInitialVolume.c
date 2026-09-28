

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

inline BOOL NNS_SndHandleIsValid (const struct NNSSndHandle * handle)
{
    return handle->player != NULL ;
}

/* NNS_SndPlayerSetInitialVolume -- NitroSystem player.c: NNS_SndPlayerSetInitialVolume. */
void NNS_SndPlayerSetInitialVolume (NNSSndHandle * handle, int volume)
{

    if (!NNS_SndHandleIsValid(handle)) return;

    handle->player->initVolume = (u8)volume;
}
