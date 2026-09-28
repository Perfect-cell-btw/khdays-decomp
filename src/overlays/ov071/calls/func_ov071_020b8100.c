/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov071_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov071_InvokeWithDataTable;

void func_ov071_020b8100(void) {
    func_ov022_0208875c(&Ov071_InvokeWithDataTable);
}
