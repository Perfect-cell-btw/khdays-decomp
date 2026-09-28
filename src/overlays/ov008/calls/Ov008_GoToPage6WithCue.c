extern int *Ov008_GetCueRequest(void);
extern void Ov008_SetTargetSlot(int arg0, int arg1);
extern void PlaySound(int arg0, int arg1);

void Ov008_GoToPage6WithCue(void)
{
    int mode = 6;

    Ov008_GetCueRequest()[3] = 1;
    Ov008_SetTargetSlot(mode, mode - 7);
    PlaySound(0, 1);
}
