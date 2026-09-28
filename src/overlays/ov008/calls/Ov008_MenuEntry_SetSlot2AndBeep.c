extern void Ov008_SetTargetSlot(int, int);
extern void PlaySound(int, int);
void Ov008_MenuEntry_SetSlot2AndBeep(void)
{
    int mode = 2;
    Ov008_SetTargetSlot(mode, mode - 3);
    PlaySound(0, 1);
}
