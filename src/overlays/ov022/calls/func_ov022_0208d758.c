/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov022_0208b848. */
extern void *func_ov022_0208b848();

void *func_ov022_0208d758() {
    return func_ov022_0208b848();
}
