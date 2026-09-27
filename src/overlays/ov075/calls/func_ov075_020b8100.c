/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov075_020b9cd0 as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov075_020b9cd0;

void func_ov075_020b8100(void) {
    func_ov022_0208875c(&func_ov075_020b9cd0);
}
