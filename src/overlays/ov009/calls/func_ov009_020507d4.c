/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov009_ClearStateFreeLists. */
extern void *Ov009_ClearStateFreeLists();

void *func_ov009_020507d4() {
    return Ov009_ClearStateFreeLists();
}
