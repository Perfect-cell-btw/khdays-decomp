

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

void NNS_FndRemoveListObject(NNSFndList * list, void * object);
void SND_ClearChannelBit(int alarmNo);
extern NNSFndList data_0204abe4;

/* ShutdownStrm -- NitroSystem stream.c: ShutdownStrm. */
void ShutdownStrm (NNSSndStrm * stream)
{
    SND_ClearChannelBit(stream->alarmNo);
    NNS_FndRemoveListObject(&data_0204abe4, stream);

    stream->activeFlag = FALSE;
}
