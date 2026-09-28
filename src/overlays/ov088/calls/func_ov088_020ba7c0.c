/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov088_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov088_InvokeWithDataTable;

void func_ov088_020ba7c0(void) {
    func_ov022_0208875c(&Ov088_InvokeWithDataTable);
}
