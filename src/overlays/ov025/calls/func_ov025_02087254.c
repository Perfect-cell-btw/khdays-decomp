/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov025_ClearStateFreeLists. */
extern void *Ov025_ClearStateFreeLists();

void *func_ov025_02087254() {
    return Ov025_ClearStateFreeLists();
}
