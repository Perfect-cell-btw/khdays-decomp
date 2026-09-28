/* Looks an entry up in page A's list (func_ov025_0208a26c). */

extern int Ov025_GetPageA();
extern int func_ov025_0208a26c();

void Ov025_GetNextMissionEntry_4(int arg0) {
    func_ov025_0208a26c(Ov025_GetPageA(arg0) + 0x13fc, arg0);
}
