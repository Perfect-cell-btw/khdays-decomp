/* Looks an entry up in page A's list (func_ov025_0208a26c). Returns the record, or NULL when the
 * index is out of range. */

extern int Ov025_GetPageA();
extern int func_ov025_0208a26c();

void *Ov025_GetNextMissionEntry_4(int arg0) {
    return func_ov025_0208a26c(Ov025_GetPageA(arg0) + 0x13fc, arg0);
}
