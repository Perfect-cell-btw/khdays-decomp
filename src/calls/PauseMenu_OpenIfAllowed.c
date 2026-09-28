extern int SoundMgr_Update(void);
extern int Ov023_CanOpenPauseMenu(int);
extern void setDualArrayEntry(int a, void *b, int c);
extern void Callbacks_ClearByteAndRun2(void);
extern void PauseMenu_Frame(void);

void PauseMenu_OpenIfAllowed(void)
{
    if (Ov023_CanOpenPauseMenu(SoundMgr_Update()) != 0) {
        setDualArrayEntry(1, (void *)PauseMenu_Frame, 0);
        Callbacks_ClearByteAndRun2();
    }
}
