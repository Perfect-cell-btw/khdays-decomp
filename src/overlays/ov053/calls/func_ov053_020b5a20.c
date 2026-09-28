/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov053_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov053_InvokeWithDataTable;

void func_ov053_020b5a20(void) {
    func_ov022_0208875c(&Ov053_InvokeWithDataTable);
}
