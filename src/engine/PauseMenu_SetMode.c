/* Sets the pause mode the main loop runs in (gPauseMode): 0 = objects update, 1 = only the
 * pause hooks run, 2 = both. PauseMenu_GetMode reads it. */

extern unsigned char gPauseMode;

void PauseMenu_SetMode(int mode)
{
    *(unsigned char *)&gPauseMode = (unsigned char)mode;
}
