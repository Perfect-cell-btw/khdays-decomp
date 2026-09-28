extern char *data_ov026_02091368;
extern void SetMasterBrightnessSub(int value);


/* Fade-in step: ramps the fade level up by 5 per frame and drives the master brightness until it
 * reaches full, then reports done. */
int Ov026_FadeInStep(void) {
    int *level = *(int **)&data_ov026_02091368;
    int v = *level;
    if (v < 0x10) {
        v += 5;
        *level = v;
        if (v > 0x10) {
            *level = 0x10;
        }
        SetMasterBrightnessSub(*level - 0x10);
        return 0;
    }
    *level = 0;
    return 1;
}
