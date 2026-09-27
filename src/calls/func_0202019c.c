/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_0201f7bc. */
extern void *func_0201f7bc();

void *func_0202019c() {
    return func_0201f7bc();
}
