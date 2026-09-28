

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

NNSSndArc * func_0201b3d8(void);
const NNSSndArcPlayerInfo * NNS_SndArcGetPlayerInfo(int playerNo);
void NNS_SndPlayerSetPlayableSeqCount(int playerNo, int seqCount);
void NNS_SndPlayerSetAllocatableChannel(int playerNo, u32 chBitFlag);
BOOL NNS_SndPlayerCreateHeap(int playerNo, NNSSndHeapHandle heap, u32 size);

/* NNS_SndArcPlayerSetup -- NitroSystem sndarc_player.c: NNS_SndArcPlayerSetup. */
BOOL NNS_SndArcPlayerSetup (NNSSndHeapHandle heap)
{
    NNSSndArc * arc = func_0201b3d8();
    int playerNo;
    const NNSSndArcPlayerInfo * playerInfo;

    for (playerNo = 0; playerNo < NNS_SND_PLAYER_NUM; ++playerNo) {
        playerInfo = NNS_SndArcGetPlayerInfo(playerNo);
        if (playerInfo == NULL) continue;

        NNS_SndPlayerSetPlayableSeqCount(playerNo, playerInfo->seqMax);
        NNS_SndPlayerSetAllocatableChannel(playerNo, playerInfo->allocChBitFlag);

        if (playerInfo->heapSize > 0 && heap != NNS_SND_HEAP_INVALID_HANDLE) {
            int i;

            for (i = 0; i < playerInfo->seqMax; i++) {
                if (!NNS_SndPlayerCreateHeap(playerNo, heap, playerInfo->heapSize)) {
                    return FALSE;
                }
            }
        }
    }

    return TRUE;
}
