/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov038_020b4b34 as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov038_020b4b34;

void func_ov038_020b3220(void) {
    func_ov022_0208875c(&func_ov038_020b4b34);
}
