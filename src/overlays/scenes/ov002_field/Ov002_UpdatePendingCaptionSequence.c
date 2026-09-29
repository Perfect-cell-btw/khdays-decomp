/* Ov002_UpdatePendingCaptionSequence; THUMB, 464 bytes, 20 relocs.
 * Queue caption ids, normalize both displays, dim the main display while
 * caption mode runs, then restore brightness and session/input state.
 * Returns one while busy and zero when complete.
 *
 * Keep nEntry materialized before the actor flag test. Propagation otherwise
 * folds it into the callee argument and changes the ROM register liveness.
 * The display loop is bottom-tested, as in the ROM.
 */
typedef struct Ov002PendingCaptionState {
    unsigned char pad00[0x51];
    unsigned char bPhase;
    short anCaptionIds[8];
    unsigned char pad62[2];
    int nBrightnessFx;
    signed char nCaptionIndex;
    unsigned char pad69[3];
} Ov002PendingCaptionState;

typedef struct Ov002SessionActorFlags {
    unsigned char pad000[0x464];
    unsigned int dwStateFlags;
} Ov002SessionActorFlags;

extern unsigned char *data_ov002_0207fa00;
extern int Ov002_Hud_RequestCaption(int nCaptionId);
extern int GetMasterBrightnessMain(void);
extern int GetMasterBrightnessSub(void);
extern int GetFrameRateMode(void);
extern void SetMasterBrightnessMain(int nBrightness);
extern void SetMasterBrightnessSub(int nBrightness);
extern int Ov002_IsGlobalModeZero(void);
extern void Ov002_SetSessionActive(int bActive, unsigned int nParts);
extern Ov002SessionActorFlags *GetEntryField20ByIndex(int nIndex);
extern int func_ov022_020886d0(int nIndex);
extern int Ov022_GetEntryField12(int nIndex);
extern void PauseMenu_SetAllowed(int bEnabled);

#pragma opt_propagation off
int Ov002_UpdatePendingCaptionSequence(void)
{
    Ov002PendingCaptionState *pState =
        (Ov002PendingCaptionState *)(data_ov002_0207fa00 + 0x8c94);
    int bBusy = 1;
    int nScreen, nSettled, nBrightness;
    unsigned int nFlags;
    int nEntry;

    switch (pState->bPhase) {
    case 0:
        while (pState->anCaptionIds[pState->nCaptionIndex] >= 0) {
            if (!Ov002_Hud_RequestCaption(pState->anCaptionIds[pState->nCaptionIndex]))
                return 1;
            pState->nCaptionIndex++;
        }
        pState->bPhase++;
        break;
    case 1:
        nSettled = 0;
        nScreen = 0;
        do {
            nBrightness = (nScreen == 0 ? GetMasterBrightnessMain() : GetMasterBrightnessSub()) << 12;
            if (nBrightness < 0) {
                nBrightness += GetFrameRateMode() == 1 ? 0x1800 : 0x1000;
                if (nBrightness >= 0) {
                    nBrightness = 0;
                    nSettled++;
                }
            } else {
                nBrightness -= GetFrameRateMode() == 1 ? 0x1800 : 0x1000;
                if (nBrightness <= 0) {
                    nBrightness = 0;
                    nSettled++;
                }
            }
            if (nScreen == 0)
                SetMasterBrightnessMain(nBrightness >> 12);
            else
                SetMasterBrightnessSub(nBrightness >> 12);
            nScreen++;
        } while (nScreen < 2);
        if (nSettled == 2) {
            pState->bPhase++;
            pState->nBrightnessFx = GetMasterBrightnessMain() << 12;
        }
        break;
    case 2:
        pState->nBrightnessFx -= GetFrameRateMode() == 1 ? 0x1800 : 0x1000;
        if (pState->nBrightnessFx <= -0x8000) {
            pState->nBrightnessFx = -0x8000;
            pState->bPhase++;
        }
        SetMasterBrightnessMain(pState->nBrightnessFx >> 12);
        break;
    case 3:
        if (Ov002_IsGlobalModeZero())
            pState->bPhase++;
        break;
    case 4:
        pState->nBrightnessFx = GetMasterBrightnessMain() << 12;
        pState->nBrightnessFx += GetFrameRateMode() == 1 ? 0x1800 : 0x1000;
        if (pState->nBrightnessFx >= 0) {
            bBusy = 0;
            pState->nBrightnessFx = 0;
            pState->bPhase = 0xff;
            Ov002_SetSessionActive(bBusy, 0xff);
        }
        SetMasterBrightnessMain(pState->nBrightnessFx >> 12);
        break;
    default:
        bBusy = 0;
    }
    if (!bBusy && (nFlags = GetEntryField20ByIndex(0)->dwStateFlags,
                  nEntry = 0, (nFlags & 0x10000000) == 0)
        && !func_ov022_020886d0(nEntry) && Ov022_GetEntryField12(0) > 0)
        PauseMenu_SetAllowed(1);
    return bBusy;
}
#pragma opt_propagation on
