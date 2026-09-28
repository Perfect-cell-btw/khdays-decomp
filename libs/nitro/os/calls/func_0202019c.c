/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to StrNCaseCmp. */
extern void *StrNCaseCmp();

void *func_0202019c() {
    return StrNCaseCmp();
}
