/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov009_0204e4a8. */
extern void *func_ov009_0204e4a8();

void *func_ov009_02054ca0() {
    return func_ov009_0204e4a8();
}
