extern char *Ov008_GetPageB(void);
extern void Ov008_SwitchMenuTab(void *context, int arg1);
extern void PlaySound(int arg0, int arg1);

void Ov008_MissionMenu_SelectTab1(void)
{
    if (*(int *)(Ov008_GetPageB() + 0x180) == 0) {
        Ov008_SwitchMenuTab(Ov008_GetPageB(), 1);
        PlaySound(0, 0);
    }
}
