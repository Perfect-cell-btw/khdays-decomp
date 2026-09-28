/* Dispatch param_2 to one of two handlers by whether param_1 is zero. */
extern void SetMasterBrightnessMain(int arg);
extern void Ov002_Field_SetSubBrightness(int arg);

void Ov002_SetBrightness(int param_1, int param_2) {
    if (param_1 != 0) {
        SetMasterBrightnessMain(param_2);
    } else {
        Ov002_Field_SetSubBrightness(param_2);
    }
}
