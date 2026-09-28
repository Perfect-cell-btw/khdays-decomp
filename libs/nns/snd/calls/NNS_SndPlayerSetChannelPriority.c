

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void SND_SetPlayerChannelPriority(int playerNo, int prio);
inline BOOL NNS_SndHandleIsValid (const struct NNSSndHandle * handle)
{
    return handle->player != NULL ;
}

/* NNS_SndPlayerSetChannelPriority -- NitroSystem player.c: NNS_SndPlayerSetChannelPriority. */
void NNS_SndPlayerSetChannelPriority (NNSSndHandle * handle, int priority)
{

    if (!NNS_SndHandleIsValid(handle)) return;

    SND_SetPlayerChannelPriority(handle->player->playerNo, priority);
}
