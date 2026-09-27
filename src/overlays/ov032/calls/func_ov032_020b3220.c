/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov032_020b56d0 as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov032_020b56d0;

void func_ov032_020b3220(void) {
    func_ov022_0208875c(&func_ov032_020b56d0);
}
