extern char *Ov008_GetMenuContext(void);
extern void Ov008_BuildActionPage(void *context, int arg1);
extern void PlaySound(int arg0, int arg1);

void Ov008_OpenActionPage7(void)
{
    char *context = Ov008_GetMenuContext();

    if (*(int *)(context + 0x30) == 0) {
        Ov008_BuildActionPage(context, 7);
        PlaySound(0, 1);
    }
}
