

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void * NNS_FndGetNextListObject(NNSFndList * list, void * object);
void NNSi_SndPlayerPause(NNSSndSeqPlayer * seqPlayer, BOOL flag);
extern NNSFndList data_0204a314;
extern void NNSi_SndPlayerPause (NNSSndSeqPlayer * seqPlayer, BOOL flag);

/* NNS_SndPlayerPauseAll -- NitroSystem player.c: NNS_SndPlayerPauseAll. */
void NNS_SndPlayerPauseAll (BOOL flag)
{
    NNSSndSeqPlayer * seqPlayer;
    NNSSndSeqPlayer * next;

    for (seqPlayer = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&data_0204a314, NULL);
         seqPlayer != NULL; seqPlayer = next) {
        next = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&data_0204a314, seqPlayer);

        NNSi_SndPlayerPause(seqPlayer, flag);
    }
}
