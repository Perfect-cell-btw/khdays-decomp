/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov076_020b9bcc as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov076_020b9bcc;

void func_ov076_020b8100(void) {
    func_ov022_0208875c(&func_ov076_020b9bcc);
}
