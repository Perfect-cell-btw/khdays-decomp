/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_02032288. */
extern void *func_02032288();

void *func_02032444() {
    return func_02032288();
}
