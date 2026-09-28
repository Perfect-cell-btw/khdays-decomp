/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov034_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov034_InvokeWithDataTable;

void func_ov034_020b3220(void) {
    func_ov022_0208875c(&Ov034_InvokeWithDataTable);
}
