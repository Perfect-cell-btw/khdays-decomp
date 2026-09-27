/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov065_020b637c. */
extern void *func_ov065_020b637c();

void *func_ov065_020b6270() {
    return func_ov065_020b637c();
}
