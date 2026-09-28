/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov030_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov030_InvokeWithDataTable;

void func_ov030_020b3220(void) {
    func_ov022_0208875c(&Ov030_InvokeWithDataTable);
}
