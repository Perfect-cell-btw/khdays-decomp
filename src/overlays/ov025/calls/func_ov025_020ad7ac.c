/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov025_020ad6e0. */
extern void *func_ov025_020ad6e0();

void *func_ov025_020ad7ac() {
    return func_ov025_020ad6e0();
}
