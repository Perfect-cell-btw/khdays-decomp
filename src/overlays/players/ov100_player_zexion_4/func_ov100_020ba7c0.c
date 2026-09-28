/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov100_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov100_InvokeWithDataTable;

void func_ov100_020ba7c0(void) {
    func_ov022_0208875c(&Ov100_InvokeWithDataTable);
}
