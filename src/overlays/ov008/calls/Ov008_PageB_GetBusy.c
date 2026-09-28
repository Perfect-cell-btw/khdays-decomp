/* Page B's busy word when active, else 0. */

extern char *Ov008_GetPageB(void);
extern int data_ov008_02090f20;
int Ov008_PageB_GetBusy(void)
{
    char *ptr = Ov008_GetPageB();
    if (data_ov008_02090f20 != 0) {
        return *(int *)(ptr + 8);
    }
    return 0;
}
