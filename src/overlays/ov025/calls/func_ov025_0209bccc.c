/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov025_GetPageA. */
extern void *Ov025_GetPageA();

void *func_ov025_0209bccc() {
    return Ov025_GetPageA();
}
