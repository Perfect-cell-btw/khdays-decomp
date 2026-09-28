

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void NNS_FndRemoveListObject(NNSFndList * list, void * object);
void * NNS_FndGetNextListObject(NNSFndList * list, void * object);
extern NNSFndList data_0204a314;
extern NNSFndList data_0204a308;
extern void ForceStopSeq(NNSSndSeqPlayer * seqPlayer);
extern void InsertPrioList(NNSSndSeqPlayer * seqPlayer);
extern void InsertPrioList (NNSSndSeqPlayer * seqPlayer);
extern void ForceStopSeq (NNSSndSeqPlayer * seqPlayer);

/* AllocSeqPlayer -- NitroSystem player.c: AllocSeqPlayer. */
NNSSndSeqPlayer * AllocSeqPlayer (int prio)
{
    NNSSndSeqPlayer * seqPlayer;

    seqPlayer = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&data_0204a308, NULL);
    if (seqPlayer == NULL) {
        seqPlayer = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&data_0204a314, NULL);

        if (prio < seqPlayer->prio) return NULL;

        ForceStopSeq(seqPlayer);
    }
    NNS_FndRemoveListObject(&data_0204a308, seqPlayer);

    seqPlayer->prio = (u8)prio;

    InsertPrioList(seqPlayer);

    return seqPlayer;
}
