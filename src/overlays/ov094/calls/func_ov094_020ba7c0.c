/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov094_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov094_InvokeWithDataTable;

void func_ov094_020ba7c0(void) {
    func_ov022_0208875c(&Ov094_InvokeWithDataTable);
}
