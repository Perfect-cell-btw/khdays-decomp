/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov002_02059654. */
extern void *func_ov002_02059654();

void *func_ov022_02095444() {
    return func_ov002_02059654();
}
