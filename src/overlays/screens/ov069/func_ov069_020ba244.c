/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov069_ClearStateFreeLists. */
extern void *Ov069_ClearStateFreeLists();

void *func_ov069_020ba244(char *r4) {
    return Ov069_ClearStateFreeLists(r4);
}
