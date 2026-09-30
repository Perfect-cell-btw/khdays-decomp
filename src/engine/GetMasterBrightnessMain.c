/* Returns the main engine's master brightness (-16..16) as last set by SetMasterBrightnessMain;
 * non-zero while the screen is faded. */

extern int gMasterBrightness;

int GetMasterBrightnessMain(void) {
    return *(signed char *)&gMasterBrightness;
}
