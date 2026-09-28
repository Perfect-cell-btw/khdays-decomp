/* Interworking tail-call veneer: calls srand_0x0208875c with &Ov046_InvokeWithDataTable as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int Ov046_InvokeWithDataTable;

void func_ov046_020b3220(void) {
    func_ov022_0208875c(&Ov046_InvokeWithDataTable);
}
