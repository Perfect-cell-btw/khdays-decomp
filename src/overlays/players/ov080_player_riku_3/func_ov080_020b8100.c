/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov080_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov080_InvokeWithDataTable;

void func_ov080_020b8100(void) {
    func_ov022_0208875c(&Ov080_InvokeWithDataTable);
}
