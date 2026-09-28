/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov074_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov074_InvokeWithDataTable;

void func_ov074_020b8100(void) {
    func_ov022_0208875c(&Ov074_InvokeWithDataTable);
}
