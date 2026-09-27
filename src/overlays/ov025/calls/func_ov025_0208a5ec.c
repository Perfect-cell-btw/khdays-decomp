/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov025_0208a4bc. */
extern void *func_ov025_0208a4bc();

void *func_ov025_0208a5ec() {
    return func_ov025_0208a4bc();
}
