/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov107_020c3e50. */
extern void *func_ov107_020c3e50();

void *func_ov237_020cc800() {
    return func_ov107_020c3e50();
}
