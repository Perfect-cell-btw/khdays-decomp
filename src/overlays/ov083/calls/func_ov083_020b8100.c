/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov083_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov083_InvokeWithDataTable;

void func_ov083_020b8100(void) {
    func_ov022_0208875c(&Ov083_InvokeWithDataTable);
}
