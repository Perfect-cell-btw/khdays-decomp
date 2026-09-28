

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void PushCommand_0A(int playerNo, int varNo, s16 var);
inline BOOL NNS_SndHandleIsValid (const struct NNSSndHandle * handle)
{
    return handle->player != NULL ;
}

/* NNS_SndPlayerWriteVariable -- NitroSystem player.c: NNS_SndPlayerWriteVariable. */
BOOL NNS_SndPlayerWriteVariable (NNSSndHandle * handle, int varNo, s16 var)
{

    if (!NNS_SndHandleIsValid(handle)) return FALSE;

    PushCommand_0A(handle->player->playerNo, varNo, var);

    return TRUE;
}
