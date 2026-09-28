/* First node with a positive count in the menu context's list at +0x13fc. */

extern int Ov008_GetMenuContext(void);
extern void Ov008_FirstPositiveCountNode(int);
void Ov008_FirstPositiveCountNodeOfList(void)
{
    Ov008_FirstPositiveCountNode(Ov008_GetMenuContext() + 0x13fc);
}
