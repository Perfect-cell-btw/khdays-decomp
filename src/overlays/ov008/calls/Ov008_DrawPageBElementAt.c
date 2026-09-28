/* Draws page B element arg2 with the argument. */

extern void Ov008_DrawPageBElement(void *, int, void *);
void Ov008_DrawPageBElementAt(void *arg0, void *arg1, void *arg2)
{
    Ov008_DrawPageBElement(arg2, 0, arg1);
}
