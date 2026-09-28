/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov004_ClearStateFreeLists. */
extern void *Ov004_ClearStateFreeLists();

void *func_ov004_0204ecec(char *r4) {
    return Ov004_ClearStateFreeLists(r4);
}
