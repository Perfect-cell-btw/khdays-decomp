/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_02023a4c. */
extern void *func_02023a4c();

void *func_02023ad0() {
    return func_02023a4c();
}
