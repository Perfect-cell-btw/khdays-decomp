/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov008_02050cd4. */
extern void *func_ov008_02050cd4();

void *func_ov008_020698ec() {
    return func_ov008_02050cd4();
}
