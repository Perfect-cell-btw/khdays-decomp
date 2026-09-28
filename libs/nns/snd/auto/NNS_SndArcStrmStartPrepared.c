

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

inline BOOL NNS_SndStrmHandleIsValid (const NNSSndStrmHandle * handle)
{
    return handle->player != NULL ;
}

/* khdays: shared-bss */
NNSSndStrmThread * sPrepareThread = 0;   /* sPrepareThread */
BOOL data_0204ad8c = 0;   /* initialized$3434 */
u8 * sDecodeBuffer = 0;   /* sDecodeBuffer */

/* NNS_SndArcStrmStartPrepared -- NitroSystem sndarc_stream.c: NNS_SndArcStrmStartPrepared. */
void NNS_SndArcStrmStartPrepared (NNSSndStrmHandle * handle)
{

    if (!NNS_SndStrmHandleIsValid(handle)) return;

    handle->player->startFlag = TRUE;
}
