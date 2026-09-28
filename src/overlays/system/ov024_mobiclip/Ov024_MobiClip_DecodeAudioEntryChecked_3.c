/* 0 when the decoder is null, else whether Ov024_MobiClip_BlitFrame (all four arguments passed
 * through: decoder, destination, width, flags) reports state 1. */

extern int Ov024_MobiClip_BlitFrame(int decoder, int dest, int width, int flags);
int Ov024_MobiClip_DecodeAudioEntryChecked_3(int param_1, int param_2, int param_3, int param_4) {
    if (param_1 == 0) return 0;
    return Ov024_MobiClip_BlitFrame(param_1, param_2, param_3, param_4) == 1;
}
