/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov009_02050570. */
extern void *func_ov009_02050570();

void *func_ov009_020507d4() {
    return func_ov009_02050570();
}
