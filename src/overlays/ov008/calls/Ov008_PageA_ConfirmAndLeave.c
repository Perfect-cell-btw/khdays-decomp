extern void Ov008_GetMenuContext(void);
extern void Ov008_SaveItemCounts(void);
extern void PlaySound(int, int);
extern void Ov008_SetTargetSlot(int, int);
void Ov008_PageA_ConfirmAndLeave(void)
{
    int mode = 0;
    Ov008_GetMenuContext();
    Ov008_SaveItemCounts();
    PlaySound(0, 1);
    Ov008_SetTargetSlot(mode, mode - 1);
}
