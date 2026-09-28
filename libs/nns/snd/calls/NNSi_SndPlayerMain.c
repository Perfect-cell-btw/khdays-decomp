

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

#define FADER_SHIFT 8

BOOL SND_IsFinishedCommandTag(u32 tag);
void SND_StartPreparedSeq(int playerNo);
void SND_SetPlayerVolume(int playerNo, int volume);
u32 SND_GetPlayerStatus(void);
extern const s16 data_02041488[128 ];
static inline
s16 SND_CalcDecibel (int scale)
{
    return data_02041488[scale];
}
void * NNS_FndGetNextListObject(NNSFndList * list, void * object);
int NNSi_SndFaderGet(const NNSSndFader * fader);
void NNSi_SndFaderUpdate(NNSSndFader * fader);
BOOL NNSi_SndFaderIsFinished(const NNSSndFader * fader);
extern NNSFndList data_0204a314;
extern void ShutdownPlayer(NNSSndSeqPlayer * seqPlayer);
extern void ForceStopSeq(NNSSndSeqPlayer * seqPlayer);
extern void ForceStopSeq (NNSSndSeqPlayer * seqPlayer);
extern void ShutdownPlayer (NNSSndSeqPlayer * seqPlayer);

/* NNSi_SndPlayerMain -- NitroSystem player.c: NNSi_SndPlayerMain. */
void NNSi_SndPlayerMain (void)
{
    NNSSndSeqPlayer * seqPlayer;
    NNSSndSeqPlayer * next;
    u32 status;
    int fader;

    status = SND_GetPlayerStatus();

    for (seqPlayer = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&data_0204a314, NULL);
         seqPlayer != NULL; seqPlayer = next) {
        next = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&data_0204a314, seqPlayer);

        if (!seqPlayer->startFlag) {
            if (SND_IsFinishedCommandTag(seqPlayer->commandTag)) {
                seqPlayer->startFlag = TRUE;
            }
        }

        if (seqPlayer->startFlag) {
            if ((status & (1 << seqPlayer->playerNo)) == 0) {
                ShutdownPlayer(seqPlayer);
                continue;
            }
        }

        NNSi_SndFaderUpdate(&seqPlayer->fader);

        fader
            = SND_CalcDecibel(seqPlayer->initVolume)
              + SND_CalcDecibel(seqPlayer->extVolume)
              + SND_CalcDecibel(seqPlayer->player->volume)
              + SND_CalcDecibel(NNSi_SndFaderGet(&seqPlayer->fader) >> FADER_SHIFT)
            ;
        if (fader < -32768) fader = -32768;
        else if (fader > 32767) fader = 32767;

        if (fader != seqPlayer->volume) {
            SND_SetPlayerVolume(seqPlayer->playerNo, fader);
            seqPlayer->volume = (s16)fader;
        }

        if (seqPlayer->status == NNS_SND_SEQ_PLAYER_STATUS_FADEOUT) {
            if (NNSi_SndFaderIsFinished(&seqPlayer->fader)) {
                ForceStopSeq(seqPlayer);
            }
        }

        if (seqPlayer->prepareFlag) {
            SND_StartPreparedSeq(seqPlayer->playerNo);
            seqPlayer->prepareFlag = FALSE;
        }
    }
}
