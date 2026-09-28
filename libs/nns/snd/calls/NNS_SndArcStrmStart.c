

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

BOOL NNS_SndArcStrmPrepare(struct NNSSndStrmHandle * handle, int strmNo, u32 offset);
void NNS_SndArcStrmStartPrepared(struct NNSSndStrmHandle * handle);
extern BOOL NNS_SndArcStrmPrepare (struct NNSSndStrmHandle * handle, int strmNo, u32 offset);
extern void NNS_SndArcStrmStartPrepared (NNSSndStrmHandle * handle);

/* khdays: shared-bss */
NNSSndStrmThread * sPrepareThread = 0;   /* sPrepareThread */
BOOL data_0204ad8c = 0;   /* initialized$3434 */
u8 * sDecodeBuffer = 0;   /* sDecodeBuffer */

/* NNS_SndArcStrmStart -- NitroSystem sndarc_stream.c: NNS_SndArcStrmStart. */
BOOL NNS_SndArcStrmStart (NNSSndStrmHandle * handle, int strmNo, u32 offset)
{
    BOOL result;

    result = NNS_SndArcStrmPrepare(handle, strmNo, offset);
    if (!result) return FALSE;

    NNS_SndArcStrmStartPrepared(handle);

    return TRUE;
}
