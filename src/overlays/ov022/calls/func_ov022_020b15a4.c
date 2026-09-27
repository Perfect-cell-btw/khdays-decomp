/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov022_020b1290. */
extern void *func_ov022_020b1290();

void *func_ov022_020b15a4() {
    return func_ov022_020b1290();
}
