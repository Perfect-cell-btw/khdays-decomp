/*
 * Provisionally store param_2 at param_1+0x20, run the classifier NNSi_G2dFontGetStringWidth
 * over (param_2, *(param_1+0x24), param_4); if it returns more than 0x3f, replace
 * the field with param_3 instead.
 */
extern int NNSi_G2dFontGetStringWidth(int a, int b, int c, int d);

void Ov002_PickTextFitting64(int param_1, int param_2, int param_3, int param_4) {
    *(int *)(param_1 + 0x20) = param_2;
    if (NNSi_G2dFontGetStringWidth(param_2, *(int *)(param_1 + 0x24), param_4, 0) > 0x3f) {
        *(int *)(param_1 + 0x20) = param_3;
    }
}
