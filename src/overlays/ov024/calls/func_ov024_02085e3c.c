/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov024_02083cf0. */
extern void *func_ov024_02083cf0();

void *func_ov024_02085e3c() {
    return func_ov024_02083cf0();
}
