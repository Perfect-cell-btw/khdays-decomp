/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov096_020bbf8c as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov096_020bbf8c;

void func_ov096_020ba7c0(void) {
    func_ov022_0208875c(&func_ov096_020bbf8c);
}
