extern int Game_RunActionScript(int);
extern int func_0201e428(int);
extern char *data_ov023_0208a784;

int Ov023_CanOpenPauseMenu(void)
{
    int r;
    r = Game_RunActionScript((int)((&data_ov023_0208a784)[1] + 0x4b88));
    r = func_0201e428(r);
    if (r == ~0xf) return 1;
    return 0;
}
