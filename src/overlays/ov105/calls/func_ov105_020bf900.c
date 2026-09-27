/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov105_020bf070. */
extern void *func_ov105_020bf070();

void *func_ov105_020bf900() {
    return func_ov105_020bf070();
}
