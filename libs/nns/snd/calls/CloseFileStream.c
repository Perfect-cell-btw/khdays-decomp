

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

BOOL FS_CloseFile(FSFile * p_file);

/* khdays: shared-bss */
NNSSndStrmThread * sPrepareThread = 0;   /* sPrepareThread */
BOOL data_0204ad8c = 0;   /* initialized$3434 */
u8 * sDecodeBuffer = 0;   /* sDecodeBuffer */

/* CloseFileStream -- NitroSystem sndarc_stream.c: CloseFileStream. */
void CloseFileStream (NNSSndStrmPlayer * player)
{
    (void)FS_CloseFile(&player->file);
}
