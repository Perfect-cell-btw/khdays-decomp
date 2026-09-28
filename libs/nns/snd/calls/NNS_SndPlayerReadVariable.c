

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

s16 SND_GetPlayerLocalVariable(int playerNo, int varNo);
inline BOOL NNS_SndHandleIsValid (const struct NNSSndHandle * handle)
{
    return handle->player != NULL ;
}

/* NNS_SndPlayerReadVariable -- NitroSystem player.c: NNS_SndPlayerReadVariable. */
BOOL NNS_SndPlayerReadVariable (NNSSndHandle * handle, int varNo, s16 * var)
{
    NNSSndSeqPlayer * seqPlayer;

    if (!NNS_SndHandleIsValid(handle)) return FALSE;

    seqPlayer = handle->player;

    if (!seqPlayer->startFlag) {
        *var = SND_DEFAULT_VARIABLE;
        return TRUE;
    }

    *var = SND_GetPlayerLocalVariable(seqPlayer->playerNo, varNo);
    return TRUE;
}
