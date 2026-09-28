/* Ov008_RemeasureTextField -- re-measure a text field's rendered width and rebuild its glyph run.
 * For a live field with text (param_2), measures it (NNSi_G2dFontGetStringWidth over param_1[8]/[9]); picks the
 * narrow (Ov008_GetCtxBlock968c) or wide (Ov008_GetDescriptor3) glyph builder by the 0x71 threshold,
 * and if the result changed, updates the head/cursor pointers (param_1[0] and [8]). */
extern int NNSi_G2dFontGetStringWidth(int *text, int len, int arg, int *out);
extern int Ov008_GetCtxBlock968c(void);
extern int Ov008_GetDescriptor3(void);

void Ov008_RemeasureTextField(int *param_1, int param_2) {
    if (param_1 != 0 && param_2 != 0) {
        int result = NNSi_G2dFontGetStringWidth((int *)param_1[8], param_1[9], param_2, 0);
        if (result > 0x70) {
            result = Ov008_GetDescriptor3();
        } else {
            result = Ov008_GetCtxBlock968c();
        }
        if (result != *param_1) {
            *param_1 = result;
            param_1[8] = result;
        }
    }
}
