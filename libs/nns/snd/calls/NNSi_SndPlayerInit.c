

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

void NNS_FndInitList(NNSFndList * list, u16 offset);
void NNS_FndAppendListObject(NNSFndList * list, void * object);
extern NNSSndSeqPlayer data_0204a320[ 16 ];
extern NNSSndPlayer data_0204a760[ 32 ];
extern NNSFndList data_0204a314;
extern NNSFndList data_0204a308;

/* NNSi_SndPlayerInit -- NitroSystem player.c: NNSi_SndPlayerInit. */
void NNSi_SndPlayerInit (void)
{
    NNSSndPlayer * player;
    int playerNo;

    NNS_FND_INIT_LIST(&data_0204a314, NNSSndSeqPlayer, prioLink);
    NNS_FND_INIT_LIST(&data_0204a308, NNSSndSeqPlayer, prioLink);

    for (playerNo = 0; playerNo < SND_PLAYER_NUM; playerNo++) {
        data_0204a320[ playerNo ].status = NNS_SND_SEQ_PLAYER_STATUS_STOP;
        data_0204a320[ playerNo ].playerNo = (u8)playerNo;
        NNS_FndAppendListObject(&data_0204a308, &data_0204a320[ playerNo ]);
    }

    for (playerNo = 0; playerNo < NNS_SND_PLAYER_NUM; playerNo++) {
        player = &data_0204a760[ playerNo ];

        NNS_FND_INIT_LIST(&player->playerList, NNSSndSeqPlayer, playerLink);
        NNS_FND_INIT_LIST(&player->heapList, NNSSndPlayerHeap, link);
        player->volume = 127;
        player->playableSeqCount = 1;
        player->allocChBitFlag = 0;
    }
}
