/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to func_ov022_0208f888. */
extern void *func_ov022_0208f888();

void *func_ov022_0208fd64() {
    return func_ov022_0208f888();
}
