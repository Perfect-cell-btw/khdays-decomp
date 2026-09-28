extern void *Ov008_GetMenuContext(void);
extern void Ov008_ShowGridPage(void *context, int arg1, int arg2);

void Ov008_AdvanceToState1IfReady(void)
{
    void *context = Ov008_GetMenuContext();

    if (*(int *)((char *)context + 0x1e78) >= 2 && *(int *)((char *)context + 0x30) == 0 && *(int *)((char *)context + 0x18) != 1) {
        Ov008_ShowGridPage(context, 1, 1);
    }
}
