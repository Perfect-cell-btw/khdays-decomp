/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov046_020b3b7c. */
extern void *func_ov046_020b3b7c();

void *func_ov046_020b3a70() {
    return func_ov046_020b3b7c();
}
