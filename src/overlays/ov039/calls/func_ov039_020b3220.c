/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov039_020b5378 as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov039_020b5378;

void func_ov039_020b3220(void) {
    func_ov022_0208875c(&func_ov039_020b5378);
}
