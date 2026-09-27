/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov025_02089894. */
extern void *func_ov025_02089894();

void *func_ov025_0208a26c() {
    return func_ov025_02089894();
}
