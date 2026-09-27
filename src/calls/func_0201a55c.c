/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_0201a80c. */
extern void *func_0201a80c();

void *func_0201a55c() {
    return func_0201a80c();
}
