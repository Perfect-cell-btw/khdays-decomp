/* Skips twice the count of stream records in page B's second resource block. */

extern int Ov025_GetPageB();
extern void Ov025_Res_BindSecondBlock();
extern void Ov025_NextStreamRecord();

void Ov025_DrainDoubleCount(int arg0) {
    int base = Ov025_GetPageB();
    Ov025_Res_BindSecondBlock(base + 0x200);
    int i = 0;
    if (arg0 * 2 <= 0) return;
    do {
        Ov025_NextStreamRecord(base + 0x200);
        i++;
    } while (i < arg0 * 2);
}
