

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

inline BOOL NNS_SndHandleIsValid (const struct NNSSndHandle * handle)
{
    return handle->player != NULL ;
}

/* NNS_SndHandleReleaseSeq -- NitroSystem player.c: NNS_SndHandleReleaseSeq. */
void NNS_SndHandleReleaseSeq (NNSSndHandle * handle)
{

    if (!NNS_SndHandleIsValid(handle)) return;

    handle->player->handle = NULL;
    handle->player = NULL;
}
