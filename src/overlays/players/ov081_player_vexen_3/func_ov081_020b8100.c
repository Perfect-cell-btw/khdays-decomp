/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov081_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov081_InvokeWithDataTable;

void func_ov081_020b8100(void) {
    func_ov022_0208875c(&Ov081_InvokeWithDataTable);
}
