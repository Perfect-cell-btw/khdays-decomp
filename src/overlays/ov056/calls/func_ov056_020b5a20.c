/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov056_020b74ec as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov056_020b74ec;

void func_ov056_020b5a20(void) {
    func_ov022_0208875c(&func_ov056_020b74ec);
}
