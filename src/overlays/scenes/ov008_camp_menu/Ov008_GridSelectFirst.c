/* Applies grid key selection 0 on the menu context. */

extern int Ov008_GetMenuContext();
extern void Ov008_GridSelectKey();

void Ov008_GridSelectFirst(void)
{
    Ov008_GridSelectKey(Ov008_GetMenuContext(), 0);
}
