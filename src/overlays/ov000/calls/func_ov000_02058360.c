/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov000_020580fc. */
extern void *func_ov000_020580fc();

void *func_ov000_02058360() {
    return func_ov000_020580fc();
}
