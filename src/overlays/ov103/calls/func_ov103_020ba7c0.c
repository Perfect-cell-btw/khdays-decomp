/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov103_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov103_InvokeWithDataTable;

void func_ov103_020ba7c0(void) {
    func_ov022_0208875c(&Ov103_InvokeWithDataTable);
}
