/* Skips twice the count of stream records in the page's second resource block. */

extern void *Ov008_GetPageB(void);
extern void Ov025_Res_BindSecondBlock(void *context);
extern void Ov025_NextStreamRecord(void *context);

void Ov008_DrainDoubleCount(int count)
{
    void *context = Ov008_GetPageB();
    int i;
    int total;

    Ov025_Res_BindSecondBlock((char *)context + 0x200);

    total = count << 1;
    i = 0;
    while (i < total) {
        Ov025_NextStreamRecord((char *)context + 0x200);
        i++;
    }
}
