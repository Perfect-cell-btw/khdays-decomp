

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void SND_PauseSeq(int playerNo, BOOL flag);

/* NNSi_SndPlayerPause -- NitroSystem player.c: NNSi_SndPlayerPause. */
void NNSi_SndPlayerPause (NNSSndSeqPlayer * seqPlayer, BOOL flag)
{
    if (seqPlayer == NULL) return;

    if (flag != seqPlayer->pauseFlag) {
        SND_PauseSeq(seqPlayer->playerNo, flag);
        seqPlayer->pauseFlag = (u8)flag;
    }
}
