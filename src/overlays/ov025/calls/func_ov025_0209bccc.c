/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov025_02084afc. */
extern void *func_ov025_02084afc();

void *func_ov025_0209bccc() {
    return func_ov025_02084afc();
}
