/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov093_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov093_InvokeWithDataTable;

void func_ov093_020ba7c0(void) {
    func_ov022_0208875c(&Ov093_InvokeWithDataTable);
}
