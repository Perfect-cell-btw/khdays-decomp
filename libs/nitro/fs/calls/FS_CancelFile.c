

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nitro/fs.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
static inline BOOL FS_IsBusy (volatile const FSFile * p_file)
{
    return (p_file->stat & 0x00000001 ) ? 1 : 0 ;
}
extern FSResult (*const (data_0204185c[]))(FSFile *);

/* FS_CancelFile -- NitroSDK fs_file.c: FS_CancelFile. */
void FS_CancelFile (FSFile *p_file)
{

	{
		OSIntrMode bak_psr = OS_DisableInterrupts();

		if (FS_IsBusy(p_file)) {
			p_file->stat |= FS_FILE_STATUS_CANCEL;
			p_file->arc->flag |= FS_ARCHIVE_FLAG_CANCELING;
		}

		(void)OS_RestoreInterrupts(bak_psr);
	}
}
