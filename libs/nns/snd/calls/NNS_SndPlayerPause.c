

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void NNSi_SndPlayerPause(NNSSndSeqPlayer * seqPlayer, BOOL flag);
extern void NNSi_SndPlayerPause (NNSSndSeqPlayer * seqPlayer, BOOL flag);

/* NNS_SndPlayerPause -- NitroSystem player.c: NNS_SndPlayerPause. */
void NNS_SndPlayerPause (NNSSndHandle * handle, BOOL flag)
{
    NNSi_SndPlayerPause(handle->player, flag);
}
