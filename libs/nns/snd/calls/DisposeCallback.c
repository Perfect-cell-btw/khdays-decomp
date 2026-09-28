

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
NNSSndArc * SND_SetActiveSlotSwap(NNSSndArc * arc);
void * NNS_SndArcGetFileAddress(u32 fileId);
void NNS_SndArcSetFileAddress(u32 fileId, void * address);

/* DisposeCallback -- NitroSystem sndarc_loader.c: DisposeCallback. */
void DisposeCallback (void * mem, NNSSndArc * arc, u32 fileId)
{
    NNSSndArc * oldArc;
    OSIntrMode old;

    if (arc == NULL) return;

    old = OS_DisableInterrupts();
    oldArc = SND_SetActiveSlotSwap(arc);

    if (mem == NNS_SndArcGetFileAddress(fileId)) {
        NNS_SndArcSetFileAddress(fileId, NULL);
    }

    (void)SND_SetActiveSlotSwap(oldArc);
    (void)OS_RestoreInterrupts(old);
}
