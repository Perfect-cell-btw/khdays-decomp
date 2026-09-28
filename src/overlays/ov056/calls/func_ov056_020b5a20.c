/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov056_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov056_InvokeWithDataTable;

void func_ov056_020b5a20(void) {
    func_ov022_0208875c(&Ov056_InvokeWithDataTable);
}
