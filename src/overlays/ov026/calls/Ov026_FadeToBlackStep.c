extern char *data_ov026_02091368;
extern void SetMasterBrightnessMain(int value);
extern void SetMasterBrightnessSub(int value);
extern void Ov026_RefreshPanelDisplay(void);

/* Fade-to-black step: 12 frames from full brightness to black, then reports -2 (done). */
int Ov026_FadeToBlackStep(void) {
    int *level = *(int **)&data_ov026_02091368;
    int result = 0;
    if (*level >= 0xc) {
        result -= 2;
    } else {
        int b = -(*level + 1) * 16 / 12;
        *level = *level + 1;
        SetMasterBrightnessMain(b);
        SetMasterBrightnessSub(b);
    }
    Ov026_RefreshPanelDisplay();
    return result;
}
