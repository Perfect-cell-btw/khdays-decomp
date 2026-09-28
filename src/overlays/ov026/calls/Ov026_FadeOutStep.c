extern char *data_ov026_02091368;
extern void SetMasterBrightnessSub(int value);


/* Fade-out step: same ramp as Ov026_FadeInStep but driving the brightness negative. */
int Ov026_FadeOutStep(void) {
    int *level = *(int **)&data_ov026_02091368;
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
