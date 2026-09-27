/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov008_0205bf04. */
extern void *func_ov008_0205bf04();

void *func_ov008_0205c574() {
    return func_ov008_0205bf04();
}
