

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

inline BOOL NNS_SndHandleIsValid (const struct NNSSndHandle * handle)
{
    return handle->player != NULL ;
}

/* NNS_SndPlayerSetSeqArcNo -- NitroSystem player.c: NNS_SndPlayerSetSeqArcNo. */
void NNS_SndPlayerSetSeqArcNo (NNSSndHandle * handle, int seqArcNo, int index)
{

    if (!NNS_SndHandleIsValid(handle)) return;

    handle->player->seqType = NNS_SND_PLAYER_SEQ_TYPE_SEQARC;
    handle->player->seqNo = (u16)seqArcNo;
    handle->player->seqArcIndex = (u16)index;
}
