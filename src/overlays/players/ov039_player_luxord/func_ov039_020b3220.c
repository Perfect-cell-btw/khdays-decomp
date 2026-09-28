/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov039_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov039_InvokeWithDataTable;

void func_ov039_020b3220(void) {
    func_ov022_0208875c(&Ov039_InvokeWithDataTable);
}
