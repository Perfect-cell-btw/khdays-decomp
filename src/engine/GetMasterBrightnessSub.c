/* Returns the sub engine's master brightness as last set by SetMasterBrightnessSub. */

extern int gMasterBrightness;

int GetMasterBrightnessSub(void) {
    return *(signed char *)((char *)&gMasterBrightness + 1);
}
