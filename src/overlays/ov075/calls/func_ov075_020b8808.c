/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov075_020b8c20. */
extern void *func_ov075_020b8c20();

void *func_ov075_020b8808() {
    return func_ov075_020b8c20();
}
