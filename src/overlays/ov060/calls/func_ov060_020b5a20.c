/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov060_020b73f4 as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov060_020b73f4;

void func_ov060_020b5a20(void) {
    func_ov022_0208875c(&func_ov060_020b73f4);
}
