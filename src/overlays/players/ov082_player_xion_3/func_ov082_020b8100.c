/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov082_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov082_InvokeWithDataTable;

void func_ov082_020b8100(void) {
    func_ov022_0208875c(&Ov082_InvokeWithDataTable);
}
