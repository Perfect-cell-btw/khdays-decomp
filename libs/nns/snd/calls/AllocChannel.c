

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

BOOL NNS_SndStrmAllocChannel(NNSSndStrm * stream, int numChannels, const u8 chNoList[]);

/* khdays: shared-bss */
NNSSndStrmThread * sPrepareThread = 0;   /* sPrepareThread */
BOOL data_0204ad8c = 0;   /* initialized$3434 */
u8 * sDecodeBuffer = 0;   /* sDecodeBuffer */

/* AllocChannel -- NitroSystem sndarc_stream.c: AllocChannel. */
BOOL AllocChannel (NNSSndStrmPlayer * player, int numChannels, const u8 chNoList[])
{

    if (player->allocChannelCount == 0) {
        if (!NNS_SndStrmAllocChannel(&player->stream, numChannels, chNoList)) {
            return FALSE;
        }
    }

    player->allocChannelCount++;

    return TRUE;
}
