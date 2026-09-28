

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

const NNSSndArcSeqInfo * NNS_SndArcGetSeqInfo(int seqNo);
extern BOOL StartSeq(NNSSndHandle * handle, int playerNo, int bankNo, int playerPrio, const NNSSndArcSeqInfo * info, int seqNo);
extern BOOL StartSeq (NNSSndHandle * handle, int playerNo, int bankNo, int playerPrio, const NNSSndArcSeqInfo * info, int seqNo);

/* NNS_SndArcPlayerStartSeq -- NitroSystem sndarc_player.c: NNS_SndArcPlayerStartSeq. */
BOOL NNS_SndArcPlayerStartSeq (NNSSndHandle * handle, int seqNo)
{
    const NNSSndArcSeqInfo * info;

    info = NNS_SndArcGetSeqInfo(seqNo);
    if (info == NULL) return FALSE;

    return StartSeq(
        handle,
        info->param.playerNo,
        info->param.bankNo,
        info->param.playerPrio,
        info,
        seqNo
        );
}
