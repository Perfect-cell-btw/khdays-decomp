/* Returns the sub engine's master brightness as last set by SetMasterBrightnessSub. */

extern int data_027e0084;

int GetMasterBrightnessSub(void) {
    return *(signed char *)((char *)&data_027e0084 + 1);
}
