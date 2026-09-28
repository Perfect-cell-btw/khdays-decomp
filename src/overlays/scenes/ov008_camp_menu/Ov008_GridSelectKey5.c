/* Applies grid key selection 5 on the menu context. */

extern int Ov008_GetMenuContext();
extern void Ov008_GridSelectKey();

void Ov008_GridSelectKey5(void)
{
    Ov008_GridSelectKey(Ov008_GetMenuContext(), 5);
}
