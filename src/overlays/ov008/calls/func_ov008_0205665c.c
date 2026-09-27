/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov008_02055c84. */
extern void *func_ov008_02055c84();

void *func_ov008_0205665c() {
    return func_ov008_02055c84();
}
