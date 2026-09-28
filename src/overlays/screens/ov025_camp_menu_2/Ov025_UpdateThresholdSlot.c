/* Switches a text object to the narrow font when the text is wider than 112 pixels (back
 * otherwise). */

extern int NNSi_G2dFontGetStringWidth();
extern int Ov025_GetDescriptor3();
extern int Ov025_GetCtxBlock968c();

void Ov025_UpdateThresholdSlot(int *arg0, int arg1) {
    if (arg0 != 0 && arg1 != 0) {
        int r = NNSi_G2dFontGetStringWidth((int *)arg0[8], arg0[9], arg1, 0);
        if (r > 0x70) r = Ov025_GetDescriptor3();
        else r = Ov025_GetCtxBlock968c();
        if (r != *arg0) {
            *arg0 = r;
            arg0[8] = r;
        }
    }
}
