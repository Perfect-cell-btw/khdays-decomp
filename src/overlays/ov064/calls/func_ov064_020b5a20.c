/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov064_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov064_InvokeWithDataTable;

void func_ov064_020b5a20(void) {
    func_ov022_0208875c(&Ov064_InvokeWithDataTable);
}
