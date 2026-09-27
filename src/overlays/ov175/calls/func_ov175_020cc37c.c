/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov107_020c6980. */
extern void *func_ov107_020c6980();

void *func_ov175_020cc37c() {
    return func_ov107_020c6980();
}
