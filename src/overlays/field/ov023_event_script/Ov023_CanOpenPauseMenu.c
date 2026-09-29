/* Runs the scene's action script and reports whether the result allows opening the pause menu. */

extern int Game_RunActionScript(int);
extern int GetMasterBrightnessMain(int);
extern char *data_ov023_0208a784;

int Ov023_CanOpenPauseMenu(void)
{
    int r;
    r = Game_RunActionScript((int)((&data_ov023_0208a784)[1] + 0x4b88));
    r = GetMasterBrightnessMain(r);
    if (r == ~0xf) return 1;
    return 0;
}
