extern char *data_ov008_02090fac;
extern void SetMasterBrightnessSub(int value);


/* Fade-out step: same ramp as Ov026_FadeInStep but driving the brightness negative. */
int Ov008_FadeOutStep(void) {
    int *level = *(int **)&data_ov008_02090fac;
    int v = *level;
    if (v < 0x10) {
        v += 5;
        *level = v;
        if (v > 0x10) {
            *level = 0x10;
        }
        SetMasterBrightnessSub(-*level);
    } else {
        *level = 0;
        return 1;
    }
    return 0;
}
