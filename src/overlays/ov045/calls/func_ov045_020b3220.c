/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov045_020b4a64 as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov045_020b4a64;

void func_ov045_020b3220(void) {
    func_ov022_0208875c(&func_ov045_020b4a64);
}
