/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov036_020b3d40. */
extern void *func_ov036_020b3d40();

void *func_ov036_020b3928() {
    return func_ov036_020b3d40();
}
