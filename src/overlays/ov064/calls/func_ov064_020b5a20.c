/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov064_020b7264 as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov064_020b7264;

void func_ov064_020b5a20(void) {
    func_ov022_0208875c(&func_ov064_020b7264);
}
