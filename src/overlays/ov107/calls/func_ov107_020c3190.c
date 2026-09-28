/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to FreeInstanceMemory. */
extern void *FreeInstanceMemory();

void *func_ov107_020c3190() {
    return FreeInstanceMemory();
}
