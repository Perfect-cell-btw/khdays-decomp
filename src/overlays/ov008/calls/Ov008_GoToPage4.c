/* Targets page 4 and plays the confirm sound. */

extern void Ov008_SetTargetSlot(int, int);
extern void PlaySound(int, int);
void Ov008_GoToPage4(void)
{
    int mode = 4;
    Ov008_SetTargetSlot(mode, mode - 5);
    PlaySound(0, 1);
}
