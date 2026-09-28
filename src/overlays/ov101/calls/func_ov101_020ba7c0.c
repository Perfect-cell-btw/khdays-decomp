/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov101_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov101_InvokeWithDataTable;

void func_ov101_020ba7c0(void) {
    func_ov022_0208875c(&Ov101_InvokeWithDataTable);
}
