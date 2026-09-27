/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov025_020ae0f0. */
extern void *func_ov025_020ae0f0();

void *func_ov025_020aebbc() {
    return func_ov025_020ae0f0();
}
