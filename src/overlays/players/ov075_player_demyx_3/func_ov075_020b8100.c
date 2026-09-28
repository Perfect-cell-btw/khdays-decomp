/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov075_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov075_InvokeWithDataTable;

void func_ov075_020b8100(void) {
    func_ov022_0208875c(&Ov075_InvokeWithDataTable);
}
