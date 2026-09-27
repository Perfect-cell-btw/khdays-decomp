/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov004_0204ea88. */
extern void *func_ov004_0204ea88();

void *func_ov004_0204ecec() {
    return func_ov004_0204ea88();
}
