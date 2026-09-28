#include "nitro/types.h"
#include "nitro/os.h"

typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

typedef enum {
    SND_CHANNEL_DATASHIFT_NONE,
    SND_CHANNEL_DATASHIFT_1BIT,
    SND_CHANNEL_DATASHIFT_2BIT,
    SND_CHANNEL_DATASHIFT_4BIT
} SNDChannelDataShift;
void SND_SetChannelVolume(u32 chBitMask, int volume, SNDChannelDataShift shift);
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
void NNSi_SndCaptureStop(void);
typedef struct NNSSndFader {
    int origin;
    int target;
    int counter;
    int frame;
} NNSSndFader;
int NNSi_SndFaderGet(const NNSSndFader * fader);
void NNSi_SndFaderUpdate(NNSSndFader * fader);
BOOL NNSi_SndFaderIsFinished(const NNSSndFader * fader);
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
extern void NNSi_SndCaptureStop (void);

/* NNSi_SndCaptureMain -- NitroSystem capture.c: NNSi_SndCaptureMain. */
void NNSi_SndCaptureMain (void)
{
    CaptureParam * cap;
    NNSSndFader * fader;
    int volume;

    cap = &data_0204acf8;

    if (cap->activeFlag && cap->type == NNS_SND_CAPTURE_TYPE_REVERB) {
        fader = &cap->fader;

        NNSi_SndFaderUpdate(fader);

        if (cap->fadeOutFlag) {
            if (NNSi_SndFaderIsFinished(fader)) {
                NNSi_SndCaptureStop();
                return;
            }
        }

        volume = (NNSi_SndFaderGet(fader) >> 8);

        if (volume != cap->volume) {
            SND_SetChannelVolume(
                cap->playChBitMask,
                volume,
                SND_CHANNEL_DATASHIFT_NONE
                );

            cap->volume = volume;
        }
    }
}
