

/* khdays: shared-bss */

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

NNSSndStrmThread * sPrepareThread = 0;   /* sPrepareThread */
BOOL data_0204ad8c = 0;   /* initialized$3434 */
u8 * sDecodeBuffer = 0;   /* sDecodeBuffer */

/* CancelMemoryStream -- NitroSystem sndarc_stream.c: CancelMemoryStream. */
void CancelMemoryStream (NNSSndStrmPlayer * player)
{
}
