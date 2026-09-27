/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov091_020bb810. */
extern void *func_ov091_020bb810();

void *func_ov091_020bb0a8() {
    return func_ov091_020bb810();
}
