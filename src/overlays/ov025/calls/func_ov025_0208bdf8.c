/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov025_0208bda0. */
extern void *func_ov025_0208bda0();

void *func_ov025_0208bdf8() {
    return func_ov025_0208bda0();
}
