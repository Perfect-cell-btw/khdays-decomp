/* MobiClip: run one slot's state machine, one call per turn.
 *
 * The states are: 0 idle, 1 starting, 2 decoding, 3 catching up, 4 draining,
 * 5 waiting for the last frame, 6 finished. Reports non-zero only when the
 * slot has nothing left to do, which is what the teardown polls for.
 */

#include "nitro/types.h"

#define QUEUE_DEPTH 10

struct MobiClipAudioStream {
    void *pStream;
    short *pLeft;
    short *pRight;
    int pad000c;
    u32 nSampleRate;
    u32 nFrameSamples;
    u32 nChannels;
    int nFilled;
    u32 nBlocks;
};

struct MobiClipFrameTimer {
    void *pStream;
    u8 alarm[0x2c];
    s64 nStartTick;
    u8 nState;
    u8 nFrontBuffer;
    u8 bPresented;
    u8 pad003b[0x40 - 0x3b];
    u32 nDecoded;
    u32 nConsumed;
    int nPresented;
    u64 nTimeBase;
    void *pfnBufferForIndex;
};

struct MobiClipGlobals {
    u8 bStopped;
    u8 pad0001[3];
    struct MobiClipAudioStream *pAudio;
    struct MobiClipFrameTimer *pMain;
    struct MobiClipFrameTimer *pSub;
};

extern struct MobiClipGlobals data_ov024_02093a2c;
extern int data_ov024_0209ba48;

extern s64 OS_GetTick(void);
extern void OS_SetAlarm(void *pAlarm, u64 nTick, void *pfnHandler, void *pArg);
extern void SND_SetChannelVolume(u32 nChannelMask, int nVolume, int nShift);
extern void SND_FlushCommand(int nChannel);
extern void OS_CancelAlarm(void *pAlarm);
extern void Ov024_MobiClip_StartAudio(struct MobiClipAudioStream *pAudio);
extern int Ov024_MobiClip_DecodeAudioEntryChecked(void *pStream);
extern void Ov024_AdvanceNodeAnim(struct MobiClipFrameTimer *pTimer);
extern void Ov024_MobiClip_FlushAudioRing(struct MobiClipAudioStream *pAudio);
extern void Ov024_MobiClip_FrameAlarm(struct MobiClipFrameTimer *pTimer);

int Ov024_MobiClip_TickSlot(struct MobiClipFrameTimer *pTimer)
{
    struct MobiClipAudioStream *pAudio;
    int bOwnsAudio;
    int nState;

    if (pTimer == 0) {
        return 1;
    }

    bOwnsAudio = 0;
    pAudio = data_ov024_02093a2c.pAudio;
    if (pAudio != 0 && pAudio->pStream == pTimer->pStream) {
        bOwnsAudio = 1;
    }
    nState = pTimer->nState;
    if (bOwnsAudio == 0) {
        pAudio = 0;
    }

    switch (nState) {
    case 0:
        return 0;

    case 1:
        pTimer->nStartTick = OS_GetTick();
        if (pAudio != 0) {
            Ov024_MobiClip_StartAudio(pAudio);
        }
        pTimer->nState = 2;
        OS_SetAlarm(pTimer->alarm, 0, (void *)&Ov024_MobiClip_FrameAlarm, pTimer);
        /* fall through */

    case 2:
        if (Ov024_MobiClip_DecodeAudioEntryChecked(pTimer->pStream) == 0
            || ((int *)&data_ov024_0209ba48)[0x39] != 0) {
            if (pAudio != 0) {
                SND_SetChannelVolume(3, 0, 0);
                SND_FlushCommand(1);
            }
            pTimer->nState = 4;
            return 0;
        }
        pTimer->nState = 3;
        /* fall through */

    case 3:
        if (pTimer->nDecoded - pTimer->nConsumed < QUEUE_DEPTH) {
            Ov024_AdvanceNodeAnim(pTimer);
            if (pAudio != 0) {
                Ov024_MobiClip_FlushAudioRing(pAudio);
            }
            pTimer->nState = 2;
        }
        return 0;

    case 4:
        if (pTimer->nDecoded <= pTimer->nConsumed) {
            pTimer->nState = 5;
        }
        return 0;

    case 5:
        if (pTimer->bPresented != 0) {
            return 0;
        }
        pTimer->nState = 6;
        OS_CancelAlarm(pTimer->alarm);
        return 1;
    }
    return 1;
}
