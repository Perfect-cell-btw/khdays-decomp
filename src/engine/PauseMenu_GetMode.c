/* Returns the pause mode the main loop runs in (gPauseMode, set by PauseMenu_SetMode):
 * 0 = objects update, 1 = only the pause callbacks run, 2 = both. */

extern int gPauseMode;

int PauseMenu_GetMode(void) {
    return *(unsigned char *)&gPauseMode;
}
