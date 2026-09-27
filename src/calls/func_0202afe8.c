/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_0202a9d0. */
extern void *func_0202a9d0();

void *func_0202afe8() {
    return func_0202a9d0();
}
