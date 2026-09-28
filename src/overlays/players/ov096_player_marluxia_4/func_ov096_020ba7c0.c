/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov096_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov096_InvokeWithDataTable;

void func_ov096_020ba7c0(void) {
    func_ov022_0208875c(&Ov096_InvokeWithDataTable);
}
