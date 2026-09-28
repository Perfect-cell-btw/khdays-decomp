

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

#define FADER_SHIFT 8

void NNSi_SndFaderSet(NNSSndFader * fader, int target, int frame);
inline BOOL NNS_SndHandleIsValid (const struct NNSSndHandle * handle)
{
    return handle->player != NULL ;
}

/* NNS_SndPlayerMoveVolume -- NitroSystem player.c: NNS_SndPlayerMoveVolume. */
void NNS_SndPlayerMoveVolume (NNSSndHandle * handle, int targetVolume, int frames)
{

    if (!NNS_SndHandleIsValid(handle)) return;

    if (handle->player->status == NNS_SND_SEQ_PLAYER_STATUS_FADEOUT) return;

    NNSi_SndFaderSet(&handle->player->fader, targetVolume << FADER_SHIFT, frames);
}
