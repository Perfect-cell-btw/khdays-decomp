/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov084_020b8a5c. */
extern void *func_ov084_020b8a5c();

void *func_ov084_020b8950() {
    return func_ov084_020b8a5c();
}
