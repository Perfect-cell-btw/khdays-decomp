/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov092_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov092_InvokeWithDataTable;

void func_ov092_020ba7c0(void) {
    func_ov022_0208875c(&Ov092_InvokeWithDataTable);
}
