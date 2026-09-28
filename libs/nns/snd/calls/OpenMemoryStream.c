

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

void MI_CpuCopy8(const void * src, void * dest, u32 size);
void * NNS_SndArcGetFileAddress(u32 fileId);

/* khdays: shared-bss */
NNSSndStrmThread * sPrepareThread = 0;   /* sPrepareThread */
BOOL data_0204ad8c = 0;   /* initialized$3434 */
u8 * sDecodeBuffer = 0;   /* sDecodeBuffer */

/* OpenMemoryStream -- NitroSystem sndarc_stream.c: OpenMemoryStream. */
BOOL OpenMemoryStream (NNSSndStrmPlayer * player, u32 fileId)
{
    player->fileOffset = (u32)NNS_SndArcGetFileAddress(fileId);

    MI_CpuCopy8(
        (const void *)(player->fileOffset),
        &player->info,
        sizeof(player->info)
        );

    return TRUE;
}
