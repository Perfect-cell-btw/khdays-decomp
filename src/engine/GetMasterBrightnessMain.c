/* Returns the main engine's master brightness (-16..16) as last set by SetMasterBrightnessMain;
 * non-zero while the screen is faded. */

extern int data_027e0084;

int GetMasterBrightnessMain(void) {
    return *(signed char *)&data_027e0084;
}
