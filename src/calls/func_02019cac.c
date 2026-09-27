/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_0201b0ec. */
extern void *func_0201b0ec();

void *func_02019cac() {
    return func_0201b0ec();
}
