/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov005_020504c0. */
extern void *func_ov005_020504c0();

void *func_ov005_02050724() {
    return func_ov005_020504c0();
}
