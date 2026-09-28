

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void SND_SetTrackParam0A(int playerNo, u32 trackBitMask, int volume);
extern const s16 data_02041488[128 ];
static inline
s16 SND_CalcDecibel (int scale)
{
    return data_02041488[scale];
}
inline BOOL NNS_SndHandleIsValid (const struct NNSSndHandle * handle)
{
    return handle->player != NULL ;
}

/* NNS_SndPlayerSetTrackVolume -- NitroSystem player.c: NNS_SndPlayerSetTrackVolume. */
void NNS_SndPlayerSetTrackVolume (NNSSndHandle * handle, u16 trackBitMask, int volume)
{

    if (!NNS_SndHandleIsValid(handle)) return;

    SND_SetTrackParam0A(
        handle->player->playerNo,
        trackBitMask,
        SND_CalcDecibel(volume)
        );
}
