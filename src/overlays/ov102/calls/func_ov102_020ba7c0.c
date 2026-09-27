/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov102_020bb794 as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov102_020bb794;

void func_ov102_020ba7c0(void) {
    func_ov022_0208875c(&func_ov102_020bb794);
}
