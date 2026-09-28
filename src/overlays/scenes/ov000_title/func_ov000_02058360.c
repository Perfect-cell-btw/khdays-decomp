/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov000_ClearStateFreeLists. */
extern void *Ov000_ClearStateFreeLists();

void *func_ov000_02058360() {
    return Ov000_ClearStateFreeLists();
}
