extern char *Ov008_GetPageB(void);
extern void Ov008_ChangeMenuSelection(void *context, int arg1, int arg2);
extern void PlaySound(int arg0, int arg1);

void Ov008_PageB_SelectPrev(void)
{
    char *context = Ov008_GetPageB();

    if (*(int *)(context + 8) == 0) {
        Ov008_ChangeMenuSelection(context, 0, 0x64);
        PlaySound(0, 2);
    }
}
