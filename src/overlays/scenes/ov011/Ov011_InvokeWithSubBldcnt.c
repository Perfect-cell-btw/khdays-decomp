/* Sets the blend brightness on one screen's blend registers (G2x_SetBlendBrightness_). */

extern void *G2x_SetBlendBrightness_();

void *Ov011_InvokeWithSubBldcnt(int this_, int arg1) {
    return G2x_SetBlendBrightness_(0x04001050, this_, arg1);
}
