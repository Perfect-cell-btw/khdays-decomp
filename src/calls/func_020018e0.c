/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_02025aac. */
extern void *func_02025aac();

void *func_020018e0() {
    return func_02025aac();
}
