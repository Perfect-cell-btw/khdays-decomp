/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov097_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov097_InvokeWithDataTable;

void func_ov097_020ba7c0(void) {
    func_ov022_0208875c(&Ov097_InvokeWithDataTable);
}
