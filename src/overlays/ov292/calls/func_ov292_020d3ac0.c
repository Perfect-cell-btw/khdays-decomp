/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov107_020c7500. */
extern void *func_ov107_020c7500();

void *func_ov292_020d3ac0() {
    return func_ov107_020c7500();
}
