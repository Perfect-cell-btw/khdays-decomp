

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

const NNSSndArcStrmInfo * NNS_SndArcGetStrmInfo(int strmNo);
extern BOOL PrepareStrm(NNSSndStrmHandle * handle, const NNSSndArcStrmInfo * strmInfo, int playerNo, int playerPrio, int strmNo, u32 offset, NNSSndStrmCallback strmCallback, void * strmCallbackArg, NNSSndArcStrmCallback sndArcStrmCallback, void * sndArcStrmCallbackArg);
extern BOOL PrepareStrm (struct NNSSndStrmHandle * handle, const NNSSndArcStrmInfo * strmInfo, int playerNo, int playerPrio, int strmNo, u32 offset, NNSSndStrmCallback strmCallback, void * strmCallbackArg, NNSSndArcStrmCallback sndArcStrmCallback, void * sndArcStrmCallbackArg);

/* khdays: shared-bss */
NNSSndStrmThread * sPrepareThread = 0;   /* sPrepareThread */
BOOL data_0204ad8c = 0;   /* initialized$3434 */
u8 * sDecodeBuffer = 0;   /* sDecodeBuffer */

/* NNS_SndArcStrmPrepare -- NitroSystem sndarc_stream.c: NNS_SndArcStrmPrepare. */
BOOL NNS_SndArcStrmPrepare (struct NNSSndStrmHandle * handle, int strmNo, u32 offset)
{
    const NNSSndArcStrmInfo * strmInfo;

    strmInfo = NNS_SndArcGetStrmInfo(strmNo);
    if (strmInfo == NULL) return FALSE;

    return PrepareStrm(
        handle,
        strmInfo,
        strmInfo->playerNo,
        strmInfo->playerPrio,
        strmNo,
        offset,
        NULL,
        NULL,
        NULL,
        NULL
        );
}
