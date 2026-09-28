/* Applies grid key selection 1 on the menu context. */

extern int Ov008_GetMenuContext();
extern void Ov008_GridSelectKey();

void Ov008_GridSelectKey1(void)
{
    Ov008_GridSelectKey(Ov008_GetMenuContext(), 1);
}
