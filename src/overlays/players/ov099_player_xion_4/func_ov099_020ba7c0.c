/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov099_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov099_InvokeWithDataTable;

void func_ov099_020ba7c0(void) {
    func_ov022_0208875c(&Ov099_InvokeWithDataTable);
}
