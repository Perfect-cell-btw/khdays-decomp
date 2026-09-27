/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov035_020b4b48 as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov035_020b4b48;

void func_ov035_020b3220(void) {
    func_ov022_0208875c(&func_ov035_020b4b48);
}
