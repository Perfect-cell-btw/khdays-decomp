/* MobiClip: stop playback and hand everything back.
 *
 * Unless a stop is already under way, both screens are asked to finish what
 * they are showing before anything is released. Then every slot's alarm is
 * cancelled, the vertical-blank presenter is uninstalled, the audio ring and
 * its two channel buffers are freed, and each slot has its stream closed, its
 * file closed and the slot itself released.
 */
#include "nitro/types.h"

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
    int nDecoded;
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

typedef u8 MobiClipFile[0x48];

struct MobiClipFileBank {
    MobiClipFile aFiles[3];
    u8 pad00d8[0x80e0 - 3 * 0x48];
    void *pfnFrameReady;
    int bStopping;
};

extern struct MobiClipFileBank data_ov024_02093a48;
extern int data_ov024_0209ba48;
extern struct MobiClipGlobals data_ov024_02093a2c;
extern struct MobiClipFrameTimer *data_ov024_02093a3c[3];
extern int data_ov024_020939ac;

extern void NNSi_FndFreeFromDefaultHeap(void *pBlock);
extern void FS_CloseFile(void *pFile);
extern int Ov024_MobiClip_TickSlot(struct MobiClipFrameTimer *pTimer);
extern void Ov024_MobiClip_ReleaseAudioChannel(void);
extern void Ov024_MobiClip_DecoderDestroy(void *pStream);
extern void Ov024_MobiClip_FlushStagedBlock(void);
extern void OS_CancelAlarm(void *pAlarm);
extern void OS_EndAlarm(void);
extern void VBlank_UnregisterCallback(int nSlot, void *pTable);

void Ov024_MobiClip_StopPlayback(void)
{
    struct MobiClipFileBank *pBank;
    struct MobiClipFrameTimer **apSlots;
    struct MobiClipAudioStream *pAudio;
    int bMain;
    int bSub;
    int i;

    pAudio = data_ov024_02093a2c.pAudio;
    pBank = &data_ov024_02093a48;
    apSlots = data_ov024_02093a3c;
    if (((int *)&data_ov024_0209ba48)[0x39] == 0) {
        pBank->bStopping = 1;
        do {
            bMain = Ov024_MobiClip_TickSlot(data_ov024_02093a2c.pMain);
            bSub = Ov024_MobiClip_TickSlot(data_ov024_02093a2c.pSub);
        } while ((bMain & bSub) != 0);
    }

    for (i = 0; i < 3; i++) {
        if (apSlots[i] != 0) {
            OS_CancelAlarm(apSlots[i]->alarm);
        }
    }
    OS_EndAlarm();
    VBlank_UnregisterCallback(1, &data_ov024_020939ac);

    if (pAudio != 0) {
        Ov024_MobiClip_ReleaseAudioChannel();
        NNSi_FndFreeFromDefaultHeap(pAudio->pLeft);
        NNSi_FndFreeFromDefaultHeap(pAudio->pRight);
        NNSi_FndFreeFromDefaultHeap(pAudio);
        data_ov024_02093a2c.pAudio = 0;
    }

    for (i = 0; i < 3; i++) {
        if (apSlots[i] != 0) {
            Ov024_MobiClip_DecoderDestroy(apSlots[i]->pStream);
            FS_CloseFile(pBank->aFiles[i]);
            NNSi_FndFreeFromDefaultHeap(data_ov024_02093a3c[i]);
            data_ov024_02093a3c[i] = 0;
        }
    }
    Ov024_MobiClip_FlushStagedBlock();
}
