

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

/* NNS_SndArcStrmGetTimeLength -- NitroSystem sndarc_stream.c: NNS_SndArcStrmGetTimeLength. */
u32 NNS_SndArcStrmGetTimeLength (NNSSndStrmHandle * handle)
{
    NNSSndStrmPlayer * player;
    u64 len;

    if (!NNS_SndStrmHandleIsValid(handle)) return 0;

    player = handle->player;

    len = player->info.loopEnd;
    len *= 1000;
    len /= player->info.sampleRate;

    return (u32)len;
}
