/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov008_02058bac. */
extern void *func_ov008_02058bac();

void *func_ov008_020594c4() {
    return func_ov008_02058bac();
}
