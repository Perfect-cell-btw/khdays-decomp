

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

void NNS_SndStrmFreeChannel(NNSSndStrm * stream);

/* khdays: shared-bss */
NNSSndStrmThread * sPrepareThread = 0;   /* sPrepareThread */
BOOL data_0204ad8c = 0;   /* initialized$3434 */
u8 * sDecodeBuffer = 0;   /* sDecodeBuffer */

/* FreeChannel -- NitroSystem sndarc_stream.c: FreeChannel. */
void FreeChannel (NNSSndStrmPlayer * player)
{

    if (player->allocChannelCount == 0) {
        return;
    }

    player->allocChannelCount--;

    if (player->allocChannelCount == 0) {
        NNS_SndStrmFreeChannel(&player->stream);
    }
}
