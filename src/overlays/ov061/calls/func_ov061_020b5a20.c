/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov061_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov061_InvokeWithDataTable;

void func_ov061_020b5a20(void) {
    func_ov022_0208875c(&Ov061_InvokeWithDataTable);
}
