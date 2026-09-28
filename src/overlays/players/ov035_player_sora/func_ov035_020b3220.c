/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov035_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov035_InvokeWithDataTable;

void func_ov035_020b3220(void) {
    func_ov022_0208875c(&Ov035_InvokeWithDataTable);
}
