

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

inline BOOL NNS_SndHandleIsValid (const struct NNSSndHandle * handle)
{
    return handle->player != NULL ;
}

/* NNS_SndPlayerSetSeqNo -- NitroSystem player.c: NNS_SndPlayerSetSeqNo. */
void NNS_SndPlayerSetSeqNo (NNSSndHandle * handle, int seqNo)
{

    if (!NNS_SndHandleIsValid(handle)) return;

    handle->player->seqType = NNS_SND_PLAYER_SEQ_TYPE_SEQ;
    handle->player->seqNo = (u16)seqNo;
}
