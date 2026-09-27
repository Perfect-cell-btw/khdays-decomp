/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov025_0208e498. */
extern void *func_ov025_0208e498();

void *func_ov025_0208eb08() {
    return func_ov025_0208e498();
}
