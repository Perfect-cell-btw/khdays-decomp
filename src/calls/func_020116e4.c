/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_020116a8. */
extern void *func_020116a8();

void *func_020116e4() {
    return func_020116a8();
}
