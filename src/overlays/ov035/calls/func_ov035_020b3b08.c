/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov035_020b4270. */
extern void *func_ov035_020b4270();

void *func_ov035_020b3b08() {
    return func_ov035_020b4270();
}
