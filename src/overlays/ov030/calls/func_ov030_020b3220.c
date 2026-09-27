/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov030_020b3e84 as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov030_020b3e84;

void func_ov030_020b3220(void) {
    func_ov022_0208875c(&func_ov030_020b3e84);
}
