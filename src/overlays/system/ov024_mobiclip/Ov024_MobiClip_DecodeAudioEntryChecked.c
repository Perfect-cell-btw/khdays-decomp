/* 0 when param_1 is null, else whether Ov024_MobiClip_StepFrame(param_1) reports state 1. */
extern int Ov024_MobiClip_StepFrame(int arg);
int Ov024_MobiClip_DecodeAudioEntryChecked(int param_1) {
    if (param_1 == 0) return 0;
    return Ov024_MobiClip_StepFrame(param_1) == 1;
}
