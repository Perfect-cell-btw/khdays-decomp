

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

void MI_CpuCopy8(const void * src, void * dest, u32 size);

/* khdays: shared-bss */
NNSSndStrmThread * sPrepareThread = 0;   /* sPrepareThread */
BOOL data_0204ad8c = 0;   /* initialized$3434 */
u8 * sDecodeBuffer = 0;   /* sDecodeBuffer */

/* ReadMemoryStream -- NitroSystem sndarc_stream.c: ReadMemoryStream. */
s32 ReadMemoryStream (NNSSndStrmPlayer * player, void * dest, u32 size, u32 offset)
{

    const u8 * src = (const u8 *)(player->fileOffset);

    MI_CpuCopy8(src + offset, dest, size);

    return (s32)size;
}
