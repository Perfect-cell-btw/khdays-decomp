/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov008_02058a28. */
extern void *func_ov008_02058a28();

void *func_ov008_0205968c() {
    return func_ov008_02058a28();
}
