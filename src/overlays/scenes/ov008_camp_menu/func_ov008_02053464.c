/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov008_ClearStateFreeLists. */
extern void *Ov008_ClearStateFreeLists();

void *func_ov008_02053464() {
    return Ov008_ClearStateFreeLists();
}
