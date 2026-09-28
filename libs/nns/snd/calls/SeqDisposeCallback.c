

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void SND_InvalidateSeqData(const void *start, const void *end);
extern void DisposeCallback(void * mem, NNSSndArc * arc, u32 fileId);
extern void DisposeCallback (void * mem, NNSSndArc * arc, u32 fileId);

/* SeqDisposeCallback -- NitroSystem sndarc_loader.c: SeqDisposeCallback. */
void SeqDisposeCallback (void * mem, u32 size, u32 data1, u32 data2)
{
    NNSSndArc * arc = (NNSSndArc *)data1;
    u32 fileId = data2;

    DisposeCallback(mem, arc, fileId);
    SND_InvalidateSeqData(mem, (u8 *)mem + size);
}
