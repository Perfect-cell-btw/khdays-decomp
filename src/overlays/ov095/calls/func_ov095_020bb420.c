/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to Ov095_BindRig. */
extern void *Ov095_BindRig();

void *func_ov095_020bb420() {
    return Ov095_BindRig();
}
