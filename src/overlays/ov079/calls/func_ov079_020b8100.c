/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov079_020b98cc as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov079_020b98cc;

void func_ov079_020b8100(void) {
    func_ov022_0208875c(&func_ov079_020b98cc);
}
