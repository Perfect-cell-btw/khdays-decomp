/* Interworking tail-call veneer: calls srand_0x0208875c with &func_ov092_020bc390 as its first argument. */
extern void func_ov022_0208875c(void *p);
extern int func_ov092_020bc390;

void func_ov092_020ba7c0(void) {
    func_ov022_0208875c(&func_ov092_020bc390);
}
