/* Shows a grid page when the menu has at least two entries and is idle. */

extern void *Ov008_GetMenuContext(void);
extern void Ov008_ShowGridPage(void *context, int arg1, int arg2);

void Ov008_AdvanceToState2IfReady(void)
{
    void *context = Ov008_GetMenuContext();

    if (*(int *)((char *)context + 0x1e78) >= 3 && *(int *)((char *)context + 0x30) == 0 && *(int *)((char *)context + 0x18) != 2) {
        Ov008_ShowGridPage(context, 2, 1);
    }
}
