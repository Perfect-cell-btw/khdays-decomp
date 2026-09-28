/* Id of the menu context's current list. */

extern int Ov008_GetMenuContext(void);
extern unsigned short Ov008_GetId10(int);
unsigned short Ov008_GetCurrentListId(void)
{
    return Ov008_GetId10(Ov008_GetMenuContext() + 0x13fc);
}
