/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov044_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov044_InvokeWithDataTable;

void func_ov044_020b3220(void) {
    func_ov022_0208875c(&Ov044_InvokeWithDataTable);
}
