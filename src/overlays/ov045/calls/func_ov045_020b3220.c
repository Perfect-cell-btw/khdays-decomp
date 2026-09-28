/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov045_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov045_InvokeWithDataTable;

void func_ov045_020b3220(void) {
    func_ov022_0208875c(&Ov045_InvokeWithDataTable);
}
