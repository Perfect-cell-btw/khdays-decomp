/* Unless busy shows the grid page when it has content. */

extern char *Ov008_GetMenuContext(void);
extern void Ov008_ShowGridPage(void *context, int arg1, int arg2);

void Ov008_ShowGridPageIfReady(void)
{
    char *context = Ov008_GetMenuContext();

    if (*(int *)(context + 0x30) == 0 && *(int *)(context + 0x18) != 0) {
        Ov008_ShowGridPage(context, 0, 1);
    }
}
