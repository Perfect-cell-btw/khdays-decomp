

/* khdays: shared-bss */

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

NNSSndStrmThread * sPrepareThread = 0;   /* sPrepareThread */
BOOL data_0204ad8c = 0;   /* initialized$3434 */
u8 * sDecodeBuffer = 0;   /* sDecodeBuffer */

/* FreePlayer -- NitroSystem sndarc_stream.c: FreePlayer. */
void FreePlayer (NNSSndStrmPlayer * player)
{

    if (player->handle != NULL) {
        player->handle->player = NULL;
        player->handle = NULL;
    }

    player->activeFlag = FALSE;
    player->startFlag = FALSE;
    player->playFlag = FALSE;
}
