/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov055_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov055_InvokeWithDataTable;

void func_ov055_020b5a20(void) {
    func_ov022_0208875c(&Ov055_InvokeWithDataTable);
}
