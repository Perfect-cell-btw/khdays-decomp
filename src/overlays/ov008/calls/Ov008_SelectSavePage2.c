/* Unless busy selects save page 2 and draws it. */

extern char *Ov008_GetMenuContext(void);
extern void Ov008_SetField20AndDispatch(void *context, int arg1);
extern void Ov008_DrawSavePage(void *context, int arg1);

void Ov008_SelectSavePage2(void)
{
    char *context = Ov008_GetMenuContext();

    if (*(int *)(context + 0x30) == 0) {
        Ov008_SetField20AndDispatch(context, 2);
        Ov008_DrawSavePage(context, 2);
    }
}
