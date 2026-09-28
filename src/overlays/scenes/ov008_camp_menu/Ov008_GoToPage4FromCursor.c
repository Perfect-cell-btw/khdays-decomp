/* Primes the sub-scene from the cursor, targets page 4 and plays the confirm sound. */

extern void Ov008_PrimeSubSceneFromCursor(int);
extern void Ov008_SetTargetSlot(int, int);
extern void PlaySound(int, int);
void Ov008_GoToPage4FromCursor(void)
{
    int mode = 4;
    Ov008_PrimeSubSceneFromCursor(6);
    Ov008_SetTargetSlot(mode, mode - 5);
    PlaySound(0, 1);
}
