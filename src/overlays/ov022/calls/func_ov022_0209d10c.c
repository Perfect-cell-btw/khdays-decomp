/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov022_0209d1c0. */
extern void *func_ov022_0209d1c0();

void *func_ov022_0209d10c() {
    return func_ov022_0209d1c0();
}
