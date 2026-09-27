/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov008_02053200. */
extern void *func_ov008_02053200();

void *func_ov008_02053464() {
    return func_ov008_02053200();
}
