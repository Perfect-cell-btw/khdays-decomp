/* 0 when param_1 is null, else whether Ov024_MobiClip_StepAudio(param_1) reports state 1. */
extern int Ov024_MobiClip_StepAudio(int arg, void *pDst);
int Ov024_MobiClip_DecodeAudioEntryChecked_5(int param_1, void *pDst) {
    if (param_1 == 0) return 0;
    return Ov024_MobiClip_StepAudio(param_1, pDst) == 1;
}
