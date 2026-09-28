/* Forwards the three arguments to the menu context's widget handler. */

extern char *Ov008_GetMenuContext(void);
extern void func_ov008_0205c574(void *context, int arg0, int arg1, int arg2);

void Ov008_Menu_ForwardToWidgets(int arg0, int arg1, int arg2)
{
    func_ov008_0205c574(Ov008_GetMenuContext() + 4, arg0, arg1, arg2);
}
