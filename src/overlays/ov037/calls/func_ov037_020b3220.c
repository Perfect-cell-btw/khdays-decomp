/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov037_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov037_InvokeWithDataTable;

void func_ov037_020b3220(void) {
    func_ov022_0208875c(&Ov037_InvokeWithDataTable);
}
