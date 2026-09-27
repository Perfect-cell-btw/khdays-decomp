/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov008_02058540. */
extern void *func_ov008_02058540();

void *func_ov008_020593cc() {
    return func_ov008_02058540();
}
