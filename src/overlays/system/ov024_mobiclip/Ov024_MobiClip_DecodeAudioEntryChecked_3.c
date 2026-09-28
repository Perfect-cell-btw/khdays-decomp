/* 0 when param_1 is null, else whether Ov024_MobiClip_BlitFrame(param_1) reports state 1. */
extern int Ov024_MobiClip_BlitFrame(int arg);
int Ov024_MobiClip_DecodeAudioEntryChecked_3(int param_1) {
    if (param_1 == 0) return 0;
    return Ov024_MobiClip_BlitFrame(param_1) == 1;
}
