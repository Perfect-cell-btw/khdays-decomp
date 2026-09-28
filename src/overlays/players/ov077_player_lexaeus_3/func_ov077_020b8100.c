/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov077_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov077_InvokeWithDataTable;

void func_ov077_020b8100(void) {
    func_ov022_0208875c(&Ov077_InvokeWithDataTable);
}
