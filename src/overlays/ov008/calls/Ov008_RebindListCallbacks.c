extern char *Ov008_GetMenuContext(void);
extern void Ov008_BeginMenuModeSwitch(char *self, int mode);
extern void PlaySound(int a, int b);
extern void Ov008_GridMenuConfirm(void);
extern void Ov008_MenuKeyUp(void);
extern void Ov008_MenuKeyDown(void);
extern char *data_ov008_02090380;

/* Once the pending transfer is done, rebinds the three list callbacks and starts the fade. */
void Ov008_RebindListCallbacks(void) {
    char *self = Ov008_GetMenuContext();
    if (*(int *)(self + 0x30) != 0) {
        return;
    }
    Ov008_BeginMenuModeSwitch(self, 0);
    *(void **)((char *)&data_ov008_02090380 + 0x24) = (void *)&Ov008_GridMenuConfirm;
    *(void **)((char *)&data_ov008_02090380 + 0x14) = (void *)&Ov008_MenuKeyUp;
    *(void **)((char *)&data_ov008_02090380 + 0x18) = (void *)&Ov008_MenuKeyDown;
    PlaySound(0, 1);
}
