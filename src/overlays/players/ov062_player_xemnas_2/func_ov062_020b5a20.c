/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov062_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov062_InvokeWithDataTable;

void func_ov062_020b5a20(void) {
    func_ov022_0208875c(&Ov062_InvokeWithDataTable);
}
