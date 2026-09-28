/* Unless busy marks page B open and draws its elements. */

extern char *Ov008_GetMenuContext(void);
extern void Ov008_UpdateMenuButton5(int arg0);
extern void Ov008_DrawPageBElement(int arg0, int arg1, int arg2);
extern void Ov008_PageB_UploadSurface154(void);

void Ov008_OpenPageB(void)
{
    char *context = Ov008_GetMenuContext();

    if (*(int *)(context + 0x30) == 0) {
        *(int *)(context + 0x24) = 1;
        Ov008_UpdateMenuButton5(0);
        Ov008_DrawPageBElement(0x14, 0, 5);
        Ov008_PageB_UploadSurface154();
    }
}
