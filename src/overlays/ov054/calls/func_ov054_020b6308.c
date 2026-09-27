/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov054_020b6a70. */
extern void *func_ov054_020b6a70();

void *func_ov054_020b6308() {
    return func_ov054_020b6a70();
}
