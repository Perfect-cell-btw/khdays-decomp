/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov091_BindRig. */
extern void *Ov091_BindRig();

void *func_ov091_020bb0a8() {
    return Ov091_BindRig();
}
