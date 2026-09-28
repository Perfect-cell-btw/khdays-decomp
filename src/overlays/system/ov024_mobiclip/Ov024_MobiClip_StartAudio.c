/* MobiClip: hand the decoded audio to the two hardware channels.
 *
 * The stream keeps its left and right sample buffers separate. Both are pushed
 * out of the data cache, channels 0 and 1 are taken, each is pointed at its own
 * buffer as a looping 16-bit stream, and an alarm is armed to fire every half
 * buffer so the decoder can refill the half that just played.
 */

#include "nitro/types.h"

struct MobiClipAudioStream {
    int pad0000;
    short *pLeft;
    short *pRight;
    int pad000c;
    int nSampleRate;
    int pad0014;
    u32 nBlockSamples;
    int pad001c;
    u32 nBlocks;
};

extern int Math_DivMod(u32 nBase, int nSampleRate);
extern void DC_StoreRange(void *pBlock, u32 nSize);
extern void SND_LockChannel(u32 nChannelMask, u32 nLockId);
extern void SND_SetupChannelPcm(int nChannel, int nFormat, const void *pData,
                                int nLoop, int nLoopStart, int nLoopLength,
                                int nVolume, int nShift, int nTimer, int nPan);
extern void SND_SetupAlarm(int nId, int nTick, int nPeriod, void *pfn, void *pArg);
extern void SND_StartTimer(u32 nChannelMask, u32 nCaptureMask,
                           u32 nAlarmMask, u32 nFlags);
extern void SND_FlushCommand(int nChannel);
extern void Ov024_MuteChannel3(void);

void Ov024_MobiClip_StartAudio(struct MobiClipAudioStream *pStream)
{
    int nTimer;

    nTimer = Math_DivMod(0x00ffb0ff, pStream->nSampleRate);
    DC_StoreRange(pStream->pLeft, (pStream->nBlocks * pStream->nBlockSamples) << 1);
    DC_StoreRange(pStream->pRight, (pStream->nBlocks * pStream->nBlockSamples) << 1);
    SND_LockChannel(3, 0);
    SND_SetupChannelPcm(0, 1, pStream->pLeft, 1, 0,
                        (pStream->nBlocks * pStream->nBlockSamples) >> 1,
                        0, 0, nTimer, 0x20);
    SND_SetupChannelPcm(1, 1, pStream->pRight, 1, 0,
                        (pStream->nBlocks * pStream->nBlockSamples) >> 1,
                        0, 0, nTimer, 0x5f);
    SND_SetupAlarm(0, nTimer * 0x64, 0, (void *)&Ov024_MuteChannel3, 0);
    SND_StartTimer(3, 0, 1, 0);
    SND_FlushCommand(1);
}
