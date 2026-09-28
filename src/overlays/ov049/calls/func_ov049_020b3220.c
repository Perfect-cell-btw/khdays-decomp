/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov049_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov049_InvokeWithDataTable;

void func_ov049_020b3220(void) {
    func_ov022_0208875c(&Ov049_InvokeWithDataTable);
}
