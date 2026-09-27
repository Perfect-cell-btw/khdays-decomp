/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov031_020b4c2c as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov031_020b4c2c;

void func_ov031_020b3220(void) {
    func_ov022_0208875c(&func_ov031_020b4c2c);
}
