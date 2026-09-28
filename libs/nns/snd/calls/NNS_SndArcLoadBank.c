

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

NNSSndArcLoadResult NNSi_SndArcLoadBank(int bankNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct SNDBankData ** pData);
extern NNSSndArcLoadResult NNSi_SndArcLoadBank (int bankNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct SNDBankData ** pData);

/* NNS_SndArcLoadBank -- NitroSystem sndarc_loader.c: NNS_SndArcLoadBank. */
BOOL NNS_SndArcLoadBank (int bankNo, NNSSndHeapHandle heap)
{
    NNSSndArcLoadResult result;

    result = NNSi_SndArcLoadBank(bankNo, NNS_SND_ARC_LOAD_ALL, heap, TRUE, NULL);

    return result == NNS_SND_ARC_LOAD_SUCESS ? TRUE : FALSE;
}
