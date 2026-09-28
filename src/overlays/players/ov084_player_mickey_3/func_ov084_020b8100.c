/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov084_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov084_InvokeWithDataTable;

void func_ov084_020b8100(void) {
    func_ov022_0208875c(&Ov084_InvokeWithDataTable);
}
