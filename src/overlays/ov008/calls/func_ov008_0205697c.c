/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov008_0205684c. */
extern void *func_ov008_0205684c();

void *func_ov008_0205697c() {
    return func_ov008_0205684c();
}
