/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov025_02086ff0. */
extern void *func_ov025_02086ff0();

void *func_ov025_02087254() {
    return func_ov025_02086ff0();
}
