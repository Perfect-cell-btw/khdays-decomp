

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

inline BOOL NNS_SndHandleIsValid (const struct NNSSndHandle * handle)
{
    return handle->player != NULL ;
}

/* NNS_SndPlayerGetSeqNo -- NitroSystem player.c: NNS_SndPlayerGetSeqNo. */
int NNS_SndPlayerGetSeqNo (NNSSndHandle * handle)
{

    if (!NNS_SndHandleIsValid(handle)) return -1;

    if (handle->player->seqType != NNS_SND_PLAYER_SEQ_TYPE_SEQ) return -1;

    return handle->player->seqNo;
}
