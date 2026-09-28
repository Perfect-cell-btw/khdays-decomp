/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov009_GetPageA. */
extern void *Ov009_GetPageA();

void *func_ov009_02054ca0() {
    return Ov009_GetPageA();
}
