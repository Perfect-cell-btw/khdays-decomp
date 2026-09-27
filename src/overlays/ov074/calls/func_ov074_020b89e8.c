/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov074_020b9150. */
extern void *func_ov074_020b9150();

void *func_ov074_020b89e8() {
    return func_ov074_020b9150();
}
