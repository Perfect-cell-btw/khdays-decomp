

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void NNS_FndInsertListObject(NNSFndList * list, void * target, void * object);
void * NNS_FndGetNextListObject(NNSFndList * list, void * object);
extern NNSFndList data_0204a314;

/* InsertPrioList -- NitroSystem player.c: InsertPrioList. */
void InsertPrioList (NNSSndSeqPlayer * seqPlayer)
{
    NNSSndSeqPlayer * next = NULL;
    while ((next = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&data_0204a314, next)) != NULL) {
        if (seqPlayer->prio < next->prio) break;
    }

    NNS_FndInsertListObject(&data_0204a314, next, seqPlayer);
}
