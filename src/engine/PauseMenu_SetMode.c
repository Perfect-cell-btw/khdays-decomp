/* Sets the pause mode the main loop runs in (data_0204bd84): 0 = objects update, 1 = only the
 * pause hooks run, 2 = both. PauseMenu_GetMode reads it. */

extern unsigned char data_0204bd84;

void PauseMenu_SetMode(int mode)
{
    *(unsigned char *)&data_0204bd84 = (unsigned char)mode;
}
