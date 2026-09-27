/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov059_020b71ec as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov059_020b71ec;

void func_ov059_020b5a20(void) {
    func_ov022_0208875c(&func_ov059_020b71ec);
}
