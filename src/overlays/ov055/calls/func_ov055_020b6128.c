/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov055_020b6540. */
extern void *func_ov055_020b6540();

void *func_ov055_020b6128() {
    return func_ov055_020b6540();
}
