

#include "nitro/types.h"
#include "nitro/os.h"

#define SND_COMMAND_BLOCK (1 << 0)

BOOL OS_ReceiveMessage(OSMessageQueue * mq, OSMessage * msg, s32 flags);
BOOL SND_FlushCommand(u32 flags);
void SND_WaitForCommandProc(u32 tag);
u32 SND_GetCurrentCommandTag(void);
typedef enum SNDChannelOut {
    SND_CHANNEL_OUT_MIXER,
    SND_CHANNEL_OUT_BYPASS
} SNDChannelOut;
typedef enum SNDOutput {
    SND_OUTPUT_MIXER,
    SND_OUTPUT_CHANNEL1,
    SND_OUTPUT_CHANNEL3,
    SND_OUTPUT_CHANNEL1_3
} SNDOutput;
void SND_StopTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
void SND_SetOutputSelector(
    SNDOutput left,
    SNDOutput right,
    SNDChannelOut channel1,
    SNDChannelOut channel3
);
typedef enum {
    NNS_SND_CAPTURE_FORMAT_PCM16,
    NNS_SND_CAPTURE_FORMAT_PCM8
} NNSSndCaptureFormat;
typedef enum {
    NNS_SND_CAPTURE_TYPE_REVERB,
    NNS_SND_CAPTURE_TYPE_EFFECT,
    NNS_SND_CAPTURE_TYPE_SAMPLING
} NNSSndCaptureType;
typedef void (*NNSSndCaptureCallback)(void * bufferL, void * bufferR, u32 len, NNSSndCaptureFormat format, void * arg);
void NNS_SndUnlockChannel(u32 chBitFlag);
void NNS_SndUnlockCapture(u32 capBitFlag);
void SND_ClearChannelBit(int alarmNo);
typedef struct NNSSndFader {
    int origin;
    int target;
    int counter;
    int frame;
} NNSSndFader;
typedef struct CaptureParam {
    BOOL activeFlag;
    NNSSndCaptureType type;
    NNSSndCaptureFormat format;
    void * bufferL;
    void * bufferR;
    u32 bufLen;
    u32 blockSize;
    int curBuffer;
    u32 chBitMask;
    u32 playChBitMask;
    u32 capBitMask;
    int alarmNo;
    int interval;
    NNSSndCaptureCallback callback;
    void * callbackArg;
    NNSSndFader fader;
    BOOL fadeOutFlag;
    int volume;
} CaptureParam;
extern CaptureParam data_0204acf8;
extern OSMessageQueue data_0204acb8;

/* NNSi_SndCaptureStop -- NitroSystem capture.c: NNSi_SndCaptureStop. */
void NNSi_SndCaptureStop (void)
{
    CaptureParam * cap = &data_0204acf8;
    u32 commandTag;
    BOOL useAlarm;

    if (!cap->activeFlag) return;

    useAlarm = cap->alarmNo >= 0 ? TRUE : FALSE;

    SND_StopTimer(
        cap->playChBitMask,
        cap->capBitMask,
        useAlarm ? (u32)(1 << cap->alarmNo) : 0,
        0
        );

    if (useAlarm) {

        commandTag = SND_GetCurrentCommandTag();
        (void)SND_FlushCommand(SND_COMMAND_BLOCK);
        SND_WaitForCommandProc(commandTag);

        while (OS_ReceiveMessage(&data_0204acb8, NULL, OS_MESSAGE_NOBLOCK)) {
        }
    }

    if (cap->capBitMask) NNS_SndUnlockCapture(cap->capBitMask);
    if (cap->chBitMask) NNS_SndUnlockChannel(cap->chBitMask);
    if (useAlarm) SND_ClearChannelBit(cap->alarmNo);

    if (cap->type == NNS_SND_CAPTURE_TYPE_EFFECT) {
        SND_SetOutputSelector(
            SND_OUTPUT_MIXER,
            SND_OUTPUT_MIXER,
            SND_CHANNEL_OUT_MIXER,
            SND_CHANNEL_OUT_MIXER
            );
    }

    cap->activeFlag = FALSE;
}
