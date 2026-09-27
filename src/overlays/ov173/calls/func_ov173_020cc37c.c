/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov107_020c7b70. */
extern void *func_ov107_020c7b70();

void *func_ov173_020cc37c() {
    return func_ov107_020c7b70();
}
