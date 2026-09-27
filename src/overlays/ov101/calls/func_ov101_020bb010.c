/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov101_020bb11c. */
extern void *func_ov101_020bb11c();

void *func_ov101_020bb010() {
    return func_ov101_020bb11c();
}
