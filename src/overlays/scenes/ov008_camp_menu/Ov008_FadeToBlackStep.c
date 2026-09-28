extern char *data_ov008_02090fac;
extern void SetMasterBrightnessMain(int value);
extern void SetMasterBrightnessSub(int value);
extern void Ov008_RefreshPanelDisplay(void);

/* Fade-to-black step: 12 frames from full brightness to black, then reports -2 (done). */
int Ov008_FadeToBlackStep(void) {
    int *level = *(int **)&data_ov008_02090fac;
    int result = 0;
    if (*level >= 0xc) {
        result -= 2;
    } else {
        int b = -(*level + 1) * 16 / 12;
        *level = *level + 1;
        SetMasterBrightnessMain(b);
        SetMasterBrightnessSub(b);
    }
    Ov008_RefreshPanelDisplay();
    return result;
}
