/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov008_02078088. */
extern void *func_ov008_02078088();

void *func_ov008_02078154() {
    return func_ov008_02078088();
}
