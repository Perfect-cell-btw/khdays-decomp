/* Menu entry widget 1 callback: sets target slot 2 (-1) and plays sound 0. */

extern void Ov008_SetTargetSlot(int, int);
extern void PlaySound(int, int);
void Ov008_MenuEntry_SetSlot2AndBeep(void)
{
    int mode = 2;
    Ov008_SetTargetSlot(mode, mode - 3);
    PlaySound(0, 1);
}
