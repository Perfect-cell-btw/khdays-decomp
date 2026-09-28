/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to StrNCaseCmp. */
extern void *StrNCaseCmp();

void *func_0202019c(const signed char *a, const signed char *b, int arg2) {
    return StrNCaseCmp(a, b, arg2);
}
