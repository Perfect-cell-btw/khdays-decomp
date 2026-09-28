/* Targets page 5 and plays the confirm sound. */

extern void Ov008_SetTargetSlot(int, int);
extern void PlaySound(int, int);
void Ov008_GoToPage5(void)
{
    int mode = 5;
    Ov008_SetTargetSlot(mode, mode - 6);
    PlaySound(0, 1);
}
