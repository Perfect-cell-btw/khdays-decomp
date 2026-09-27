/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov095_020bb9a4. */
extern void *func_ov095_020bb9a4();

void *func_ov095_020bb420() {
    return func_ov095_020bb9a4();
}
