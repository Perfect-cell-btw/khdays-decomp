/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov034_020b5558 as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov034_020b5558;

void func_ov034_020b3220(void) {
    func_ov022_0208875c(&func_ov034_020b5558);
}
